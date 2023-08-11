#!/bin/bash
project_dir=$(dirname "$0")

# Determine the operating system
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    qt_paths=($(find /bin/ /usr/bin/ -name "qmake" 2>/dev/null))
elif [[ "$OSTYPE" == "msys" ]]; then
    # Windows
    qt_paths=($(find /C/ /D/ -name "qmake.exe" 2>/dev/null))
else
    echo "Unsupported operating system."
    exit 1
fi

# Check if any Qt installations were found
if [ ${#qt_paths[@]} -eq 0 ]; then
    echo "No Qt installations found.
    Enter path manually:"
    read path

# Convert backslashes to forward slashes using parameter substitution
converted_path="${path//\\//}"

    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
        qt_paths=($(find "$converted_path" -name "qmake" 2>/dev/null))
    elif [[ "$OSTYPE" == "msys" ]]; then
    # Windows
        qt_paths=($(find "$converted_path" -name "qmake.exe" 2>/dev/null))
    fi
    if [ ${#qt_paths[@]} -eq 0 ]; then
        echo "No Qt installations found."
        read name
    exit 1
    fi
fi

# Assume the first Qt installation found as the one to use
qt_path="${qt_paths[0]}"



build_dir="$project_dir/build/"

# Create build directory if it doesn't exist
mkdir -p "$build_dir"
cd "$build_dir"

# Compile the project
"$qt_path" -makefile "$project_dir"
make -j$(nproc) # Adjust the number of jobs to match your system's CPU cores

# Run the compiled executable
executable_name=$(basename "$(find . -name "Nerv.exe" -o -name "Nerv")")
if [ -n "$executable_name" ]; then
    if [[ "$OSTYPE" == "msys" ]]; then
        # On Windows, run the executable directly
        "./$executable_name"
    else
        # On Linux, run the executable
        "./$executable_name"
    fi
else
    echo "Executable not found."
fi
