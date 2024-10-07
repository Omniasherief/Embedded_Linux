
#  Extract Script 📥

Welcome to the **Extract Script**! This handy little tool lets you extract various types of archive files (like `.zip`, `.tar`, `.gz`, and more) using a simple command. Say goodbye to the hassle of remembering different extraction commands!

## 🚀 Features

- **Supports a wide range of archive formats 📂**:
  - `.zip`
  - `.tar`
  - `.tar.gz`
  - `.tar.bz2`
  - `.rar`
  - `.gz`
  - `.bz2`
  - `.7z`
  - ...and many more!

## 🛠️ How to Run the Script

### You have 2 options!

#### Option 1: Running the Script Directly

1. **Save the Script**:
   Create a file named `extract.sh` and copy the extraction code into it.

2. **Make the Script Executable**:
   Open your terminal and run:
   ```bash
   chmod +x extract.sh
   ```

3. **Run the Script**:
   Now you can extract files by passing the archive you want to extract as an argument:
   ```bash
   ./extract.sh  path/to/your/archive.ext
   ```

---

#### Option 2: Use the Function in Your Terminal

1. **Add the Function to Your Shell**:
   Open your `~/.bashrc` file in your favorite text editor (e.g., `vim`, `nano`, or `gedit`):
   ```bash
   vim ~/.bashrc
   ```

   Then, add the following function at the end of the file:

   ```bash
   extract () {
       if [ -f "$1" ]; then
           echo "✨ Extracting file: $1"
           case "$1" in
               *.tar.bz2)  tar xvjf "$1" ;;
               *.tar.gz)   tar xvzf "$1" ;;
               *.tar.xz)   tar xvJf "$1" ;;
               *.bz2)      bunzip2 "$1" ;;
               *.rar)      rar x "$1" ;;
               *.gz)       gunzip "$1" ;;
               *.tar)      tar xvf "$1" ;;
               *.tbz2)     tar xvjf "$1" ;;
               *.tgz)      tar xvzf "$1" ;;
               *.zip)
                   dir=$(echo "$1" | sed 's/\(.*\)\.zip/\1/')
                   mkdir -p "$dir"
                   unzip "$1" -d "$dir"
                   ;;
               *.Z)        uncompress "$1" ;;
               *.7z)       7z x "$1" ;;
               *) echo "❓ Oops! Don't know how to extract '$1'" ;;
           esac
       else
           echo "🚫 $1 is not a valid file!"
       fi
   }
   ```

2. **Save and Reload**:
   After adding the function, run this command to refresh your terminal settings:
   ```bash
   source ~/.bashrc
   ```

## 📖 Usage

Once you have either option set up, extracting an archive is as easy as:

```bash
extract path/to/your/archive.ext
```

### 🎉 Example:

```bash
extract ~/Downloads/example.zip
```

Now sit back and watch your files get extracted effortlessly! 😄


