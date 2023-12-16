<h1 align="center">JPEG Image Recovery from Corrupted SD Card</h1>



<p align="center">This repository contains a C program for recovering JPEG images from a corrupted SD card.</p>

---

### 🚀 Features:

- Recovers JPEG images from corrupted SD cards.
- Handles multiple images on the card.
- Creates filenames with sequential numbering.

---

### 🛠️ Usage

1. **Install the necessary libraries:** The program requires the `cs50` library. Install it using your system's package manager or download it from the [official website](https://cs50.harvard.edu/x/2021/library/).
2. **Compile the program:** Save the code as a file (e.g., recover.c) and compile it using a C compiler. For example, on Linux or macOS, you can use the following command:
   ```bash
   gcc -o recover recover.c -lcs50
   
3. **Run the program:** Provide the filename of the SD card image as an argument. For example:
   ```bash
   ./recover sdcard.img
   ```
   

4. **Output:** The program will create JPEG files named 000.jpg, 001.jpg, and so on, in the same directory as the program.

### 🚧 Limitations
This program only works with JPEG images. It cannot recover other types of files.
The program may not be able to recover all images from a severely corrupted card.
The program assumes that the SD card image is a raw file, not a formatted disk image.

### 🤝 Contributing
If you have any suggestions or improvements for this program, please feel free to create a pull request.

### 📝 License
This project is licensed under the MIT License - see the LICENSE file for details.
