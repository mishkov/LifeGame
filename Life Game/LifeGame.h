#pragma once

namespace LifeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ LifeGame
	/// </summary>
	public ref class LifeGame : public System::Windows::Forms::Form
	{
	private:
		int index = 0;
	public:
		LifeGame(unsigned int width, unsigned int height)
		{
			this->Size = System::Drawing::Size(width, height);

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void onLifeUpdate(Object^ /*myObject*/, EventArgs^ /*myEventArgs*/)
		{
			this->myTimer->Stop();
			// TODO: Update Life here
			Graphics^ g = LifeArea->CreateGraphics();
			Brush^ brush = Brushes::Green;
			g->FillRectangle(brush, index * 10, 0, 10, 10);
			index++;
			this->myTimer->Enabled = true;
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~LifeGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::PictureBox^ LifeArea;
		System::Windows::Forms::Button^ startButton;
		System::Windows::Forms::Button^ stopButton;
		System::Windows::Forms::Timer^ myTimer;
		int updateFrequencyInSeconds = 1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			myTimer = gcnew Timer();

			/* Adds the event and the event handler for the method that will
				process the timer event to the timer. */
			myTimer->Tick += gcnew EventHandler(this, &LifeGame::onLifeUpdate);

			// Sets the timer interval to 5 seconds.
			myTimer->Interval = 100 * updateFrequencyInSeconds;


			this->LifeArea = (gcnew System::Windows::Forms::PictureBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->stopButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LifeArea))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->LifeArea->Location = System::Drawing::Point(12, 12);
			this->LifeArea->Name = L"pictureBox1";
			this->LifeArea->Size = System::Drawing::Size(928, 302);
			this->LifeArea->TabIndex = 0;
			this->LifeArea->TabStop = false;
			this->LifeArea->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &LifeGame::sd);
			// 
			// button1
			// 
			const int buttonPadding = 10;
			this->startButton->Name = L"button1";
			this->startButton->Size = System::Drawing::Size(80, 30);
			int buttonYPosition = this->ClientSize.Height - this->startButton->Size.Height - buttonPadding;
			this->startButton->Location = System::Drawing::Point(buttonPadding, buttonYPosition);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &LifeGame::button1_Click);
			//
			// stop button
			//
			this->stopButton->Name = L"stopButton";
			this->stopButton->Size = System::Drawing::Size(80, 30);
			int buttonXPosition = this->ClientSize.Width - this->stopButton->Width - buttonPadding;
			buttonYPosition = this->ClientSize.Height - this->stopButton->Size.Height - buttonPadding;
			this->stopButton->Location = System::Drawing::Point(buttonXPosition, buttonYPosition);
			this->stopButton->TabIndex =2;
			this->stopButton->Text = L"Stop";
			this->stopButton->UseVisualStyleBackColor = true;
			this->stopButton->Click += gcnew System::EventHandler(this, &LifeGame::onStopButtonClicked);
			// 
			// LifeGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			// this->ClientSize = System::Drawing::Size(952, 538);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->stopButton);
			this->Controls->Add(this->LifeArea);
			this->Name = L"LifeGame";
			this->Text = L"LifeGame";
			this->Load += gcnew System::EventHandler(this, &LifeGame::LifeGame_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LifeArea))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LifeGame_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void sd(System::Object^ sender, System::Windows::Forms::LayoutEventArgs^ e) {
	}
	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			myTimer->Start();
		}

		System::Void onStopButtonClicked(System::Object^ sender, System::EventArgs^ e) {
			myTimer->Stop();
		}
	};
}
