#!/bin/bash
# Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
LOGFILE=make_log.txt
EXEC=z80_emu

# make all > "$LOGFILE" 2>&1
make -j4 > "$LOGFILE" 2>&1

if [ $? -eq 0 ]; then
    echo "Build successful. Running the executable..."
    ./build/bin/"$EXEC"
else
    echo "Build failed. Displaying error log:"
    cat "$LOGFILE"
fi

# rm -f "$LOGFILE"