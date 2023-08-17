#!/bin/bash

# Set the path to your Qt installation
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

# Get the directory of the script
project_dir=$(dirname "$0")

# Create and navigate to the build directory
mkdir -p "$project_dir/build"
cd "$project_dir/build"

# Generate build files using CMake
cmake -DCMAKE_PREFIX_PATH=$QT_INSTALL_PATH "$project_dir"

# Build the project using make (adjust the number of jobs as needed)
make -j$(nproc)

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful. Running the executable..."
    # Run the compiled program
    ./Nerv
else
    echo "Build failed."
fi