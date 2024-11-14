# Z80エミュレータ Makefile
# Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)

# 実行ファイルの名前とディレクトリ設定
TARGET_NAME = z80_emu
SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin
EXEC_FILE = build/$(TARGET_NAME).exe  # 実行ファイルのパスを指定

# 出力ファイルのパス
ELF_FILE = $(BIN_DIR)/$(TARGET_NAME).elf
HEX_FILE = $(BIN_DIR)/$(TARGET_NAME).hex
BIN_FILE = $(BIN_DIR)/$(TARGET_NAME).bin
MAP_FILE = $(BIN_DIR)/$(TARGET_NAME).map

# ソースファイルとオブジェクトファイル
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# コンパイルおよびリンク設定
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -Wl,-Map=$(MAP_FILE)  # マップファイル生成オプション

# ビルドルール
all: $(EXEC_FILE) $(HEX_FILE) $(BIN_FILE)

# 実行ファイル(.exe)の生成
$(EXEC_FILE): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(EXEC_FILE) $(LDFLAGS)
	@echo "Generated executable: $(EXEC_FILE)"

# ELFファイルの生成
$(ELF_FILE): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(ELF_FILE) $(LDFLAGS)
	@echo "Generated ELF file: $(ELF_FILE)"
	@echo "Generated MAP file: $(MAP_FILE)"

# HEXファイルの生成
$(HEX_FILE): $(ELF_FILE)
	@objcopy -O ihex $(ELF_FILE) $(HEX_FILE)
	@echo "Generated HEX file: $(HEX_FILE)"

# BINファイルの生成
$(BIN_FILE): $(ELF_FILE)
	@objcopy -O binary $(ELF_FILE) $(BIN_FILE)
	@echo "Generated BIN file: $(BIN_FILE)"

# オブジェクトファイルの生成ルール
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# クリーンアップ
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned up all generated files."