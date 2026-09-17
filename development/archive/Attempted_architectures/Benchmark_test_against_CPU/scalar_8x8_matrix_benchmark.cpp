#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using u8 = std::uint8_t;
using u32 = std::uint32_t;

constexpr int N = 8;

// Scalar unsigned 8-bit matrix multiplication.
// Matches the current FPGA arithmetic:
//   A, B : unsigned 8-bit
//   C    : unsigned 32-bit accumulation
void matmul8x8(const u8 A[N][N], const u8 B[N][N], u32 C[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;

            for (int k = 0; k < N; ++k) {
                C[i][j] += static_cast<u32>(A[i][k]) *
                           static_cast<u32>(B[k][j]);
            }
        }
    }
}

bool compare_matrix(const u32 A[N][N], const u32 B[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] != B[i][j]) {
                std::cerr << "Mismatch at C[" << i << "][" << j << "]: "
                          << A[i][j] << " != " << B[i][j] << '\n';
                return false;
            }
        }
    }
    return true;
}

void print_matrix(const u32 M[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(6) << M[i][j];
        }
        std::cout << '\n';
    }
}

int main()
{
    // Same 8x8 matrices used by the current FPGA testbench.
    const u8 A[N][N] = {
        { 1,  2,  3,  4,  5,  6,  7,  8},
        { 9, 10, 11, 12, 13, 14, 15, 16},
        {17, 18, 19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30, 31, 32},
        {33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48},
        {49, 50, 51, 52, 53, 54, 55, 56},
        {57, 58, 59, 60, 61, 62, 63, 64}
    };

    const u8 B[N][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {2, 3, 4, 5, 6, 7, 8, 9},
        {3, 4, 5, 6, 7, 8, 9, 10},
        {4, 5, 6, 7, 8, 9, 10, 11},
        {5, 6, 7, 8, 9, 10, 11, 12},
        {6, 7, 8, 9, 10, 11, 12, 13},
        {7, 8, 9, 10, 11, 12, 13, 14},
        {8, 9, 10, 11, 12, 13, 14, 15}
    };

    const u32 expected[N][N] = {
        { 204,  240,  276,  312,  348,  384,  420,  456},
        { 492,  592,  692,  792,  892,  992, 1092, 1192},
        { 780,  944, 1108, 1272, 1436, 1600, 1764, 1928},
        {1068, 1296, 1524, 1752, 1980, 2208, 2436, 2664},
        {1356, 1648, 1940, 2232, 2524, 2816, 3108, 3400},
        {1644, 2000, 2356, 2712, 3068, 3424, 3780, 4136},
        {1932, 2352, 2772, 3192, 3612, 4032, 4452, 4872},
        {2220, 2704, 3188, 3672, 4156, 4640, 5124, 5608}
    };

    u32 C[N][N] = {};

    // Correctness test.
    matmul8x8(A, B, C);

    std::cout << "========================================\n";
    std::cout << "8x8 Scalar Matrix Multiplication\n";
    std::cout << "========================================\n\n";

    std::cout << "Computed C:\n";
    print_matrix(C);

    if (!compare_matrix(C, expected)) {
        std::cout << "\nCORRECTNESS TEST FAILED\n";
        return 1;
    }

    std::cout << "\nCORRECTNESS TEST PASSED\n";

    // Benchmark settings.
    // Each repetition performs one complete 8x8 matrix multiplication.
    const std::vector<std::uint64_t> repetitions = {
        1'000,
        10'000,
        100'000,
        1'000'000,
        10'000'000
    };

    // Prevent the compiler from optimizing the benchmark result away.
    volatile u32 benchmark_sink = 0;

    std::cout << "\n========================================\n";
    std::cout << "PC Scalar Benchmark\n";
    std::cout << "========================================\n";
    std::cout << "Data type : unsigned 8-bit\n";
    std::cout << "Accumulator: unsigned 32-bit\n";
    std::cout << "Algorithm : scalar triple-loop\n";
    std::cout << "Matrix    : 8x8\n";
    std::cout << "Operations/multiply: "
              << (N * N * N) << " MACs\n\n";

    for (std::uint64_t reps : repetitions) {
        auto start = std::chrono::steady_clock::now();

        for (std::uint64_t r = 0; r < reps; ++r) {
            matmul8x8(A, B, C);
            benchmark_sink ^= C[r % N][r % N];
        }

        auto end = std::chrono::steady_clock::now();

        const double total_ms =
            std::chrono::duration<double, std::milli>(end - start).count();

        const double total_ns =
            std::chrono::duration<double, std::nano>(end - start).count();

        const double ns_per_matrix = total_ns / static_cast<double>(reps);
        const double matrices_per_second =
            static_cast<double>(reps) /
            (total_ms / 1000.0);

        const double macs_per_second =
            matrices_per_second * (N * N * N);

        std::cout << "Repetitions: " << std::setw(10) << reps
                  << " | Total: " << std::fixed << std::setprecision(3)
                  << std::setw(10) << total_ms << " ms"
                  << " | Per 8x8: " << std::setw(10) << ns_per_matrix
                  << " ns"
                  << " | Matrices/s: " << std::setw(12)
                  << matrices_per_second
                  << " | MAC/s: " << std::setw(14)
                  << macs_per_second
                  << '\n';
    }

    std::cout << "\nBenchmark sink: " << benchmark_sink << '\n';
    std::cout << "========================================\n";

    return 0;
}
