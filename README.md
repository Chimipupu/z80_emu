# Z80エミュレータ(開発中)
CでZ80のCPUをエミュレート👩‍💻

## 📍実行

### Linux環境

```shell
chmod +x make.sh
./make.sh
```

### 📍Windows環境

```shell
bash make.sh
```

## 📍実装状況
**凡例(✅テスト完了、🆗実装済み、🚩TODO、❌TBD)**

- 📍CPU
  - 📍レジスタ
    - 🆗AF,BC,DE,HL,AF',BC',DE',HL',IX,IY,PC,SP
  - 📍命令セット
    - 🆗NOP,HALT,IND,INDR,INI,INIR
  - 📍フェッチ
  - 📍デコード
  - 実行
- ❌CTC
- ❌DMA
- ❌SIO
- 🚩ROM
  - 🚩4KB ～ 64KB
- 🚩RAM
  - 🚩4KB ～ 64KB
