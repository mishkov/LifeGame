#include "LifeGame.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
[STAThread]

Void main(){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LifeGame::LifeGame form(800, 600);
	// Define the border style of the form to a dialog box.
	form.FormBorderStyle = FormBorderStyle::FixedDialog;

	// Set the MaximizeBox to false to remove the maximize box.
	form.MaximizeBox = false;

	// Set the MinimizeBox to false to remove the minimize box.
	form.MinimizeBox = false;

	// Set the start position of the form to the center of the screen.
	form.StartPosition = FormStartPosition::CenterScreen;

	Application::Run(%form);
}
