---

# Voice Assistant (Alexa-like)

This project implements a simple voice assistant using Python that performs various tasks based on voice commands. It uses text-to-speech (TTS) for output, speech recognition for input, and integrates with several web services for additional functionalities.

## Features

- **Text-to-Speech (TTS)**: Converts text responses into speech.
- **Speech Recognition**: Recognizes and processes voice commands.
- **Date and Time**: Provides current date and time information.
- **News**: Fetches and reads out the latest news.
- **Web Search**: Searches for answers to questions using Google.
- **YouTube Music**: Plays music from YouTube based on commands.
- **Wikipedia**: Fetches information from Wikipedia.

## Requirements

- Python 3.x
- Libraries: `gtts`, `speech_recognition`, `requests`, `beautifulsoup4`, `wikipedia`, `pywhatkit`
- `mpg123` (for playing MP3 files on some systems)

## Installation

1. **Install Python**: Ensure you have Python 3.x installed. You can download it from [python.org](https://www.python.org/).

2. **Install Required Libraries**:
   ```bash
   pip install gtts speech_recognition requests beautifulsoup4 wikipedia pywhatkit
   ```

3. **Install `mpg123`** (for playing MP3 files, if required):
   - On Debian-based systems:
     ```bash
     sudo apt-get install mpg123
     ```
   - On macOS, you can install it via Homebrew:
     ```bash
     brew install mpg123
     ```

## Usage

1. **Run the Script**: Execute the script using Python:
   ```bash
   python3 your_script_name.py
   ```

2. **Commands**: The assistant responds to the following commands:
   - **"الساعة" / "ساعه" / "وقت"**: Provides the current time.
   - **"تاريخ" / "يوم كام"**: Provides the current date.
   - **"مين عملك"**: Replies with "أمنية".
   - **"عاملة إيه" / "ازيك" / "كيف حالك" / "إيه الأخبار"**: Replies with "بخير".
   - **"عايشة فين" / "عنوانك"**: Replies with "في نفس عنوانك".
   - **"الاخبار" / "الجديد"**: Fetches and reads the latest news.
   - **"سؤال"**: Searches for an answer to a question using Google.
   - **"اغنيه" / "موسيقى" / "سوره" / "صوره"**: Plays a song on YouTube.
   - **"مين"**: Fetches a summary from Wikipedia about a specified topic.
   - **"غبيه"**: Replies with "انا لست غبيه اعطني فرصة أخرى".
   - **"إنهاء" / "خروج" / "سلام"**: Exits the program.

## Code Overview

- **`AlexaSpeaks(text)`**: Converts text to speech and plays it.
- **`AlexaListens()`**: Listens for voice commands and returns recognized text.
- **`Run()`**: Main function that continuously listens for commands and processes them.

## Troubleshooting

- **Audio Issues**: Ensure your microphone is correctly configured and working.
- **Command Recognition**: If commands are not recognized correctly, adjust the `phrase_time_limit` in the `AlexaListens` function or improve microphone sensitivity.
- **Missing Libraries**: Make sure all required libraries are installed. Check installation instructions if you encounter any issues.

