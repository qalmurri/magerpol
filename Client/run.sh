GODOT=~/Downloads/Godot_v4.5.1-stable_linux.x86_64
PROJECT=~/Project/godot/viavlo/Client/
CPUPROJ="$PROJECT/cpp"

CLEAR=false
BUILD=false
EDITOR=false

# Parse arguments
for arg in "$@"; do
    case $arg in
        -c) CLEAR=true ;;
        -b) BUILD=true ;;
        -e) EDITOR=true ;;
    esac
done

cd "$CPUPROJ" || exit

if $CLEAR; then
    echo "Clearing C++ extension..."
    scons -c
    exit 1
fi

if $BUILD || $CLEAR; then
    echo "Building C++ extension..."
    if ! scons -j$(nproc); then
        echo "Build failed"
        exit 1
    fi
fi

echo "Starting Godot Editor..."
"$GODOT" --editor --path "$PROJECT"
