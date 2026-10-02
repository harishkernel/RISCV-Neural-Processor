using System.Windows;

namespace ProjectAgentGateV.Views;

public partial class NoticeDialog : Window
{
    public NoticeDialog(string title, string message)
    {
        InitializeComponent();
        DialogTitle.Text = title;
        DialogMessage.Text = message;
    }
    private void Close_Click(object sender, RoutedEventArgs e) => Close();
}
