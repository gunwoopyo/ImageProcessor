# ImageProcessor

C++ 기반의 CLI 이미지 처리 프로그램 과제입니다.

## 개발 환경
- Language: C++
- IDE: Visual Studio
- Platform: Windows
- Configuration: Release x64

## 지원 기능
- Grayscale
- blur
- Brightness / Contrast
- horizontal / vertical
- threshold
  
```text
## 실행 방법

./ImageProcessor.exe --input input.bmp --output result.bmp --filter grayscale
./ImageProcessor.exe --input input.bmp --output result.bmp --filter blur
./ImageProcessor.exe --input input.bmp --output result.bmp --filter bright 50
./ImageProcessor.exe --input input.bmp --output result.bmp --filter contrast 50
./ImageProcessor.exe --input input.bmp --output result.bmp --filter horizontal
./ImageProcessor.exe --input input.bmp --output result.bmp --filter vertical
./ImageProcessor.exe --input input.bmp --output result.bmp --filter blur --threshold 100


감사합니다.
