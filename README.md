# ImageProcessor 과제 제출

## 구현 항목

- grayscale
- blur + threshold
- bright / contrast
- horizontal / vertical


## 실행 명령어 (예시)

<!-- 예시 입니다. 기존 예시를 지우고 구현한 항목에 맞게 명령어를 작성해주세요. -->

```powershell
# Grayscale 변환

.\x64\Release\ImageProcessor.exe --input 3_chelsea_cat.bmp --output .\Resource\grayscale.bmp --filter grayscale
```

```powershell
# Blur 처리 + 임계값 흑백처리
.\x64\Release\ImageProcessor.exe --input 1_astronaut.bmp --output .\Resource\blurThreshold.bmp --filter blur --threshold 100
```

```powershell
# 밝기 조절
.\x64\Release\ImageProcessor.exe --input 3_chelsea_cat.bmp --output .\Resource\bright.bmp --filter bright 50
```

```powershell
# 대비 조절 
.\x64\Release\ImageProcessor.exe --input 5_checkerboard.bmp --output .\Resource\contrast.bmp --filter contrast 50

```

```powershell
# 상하 반전
.\x64\Release\ImageProcessor.exe --input 1_astronaut.bmp --output .\Resource\vertical.bmp --filter vertical
```
```powershell
# 좌우 반전
.\x64\Release\ImageProcessor.exe --input 2_coffee.bmp --output .\Resource\horizontal.bmp --filter horizontal
```





