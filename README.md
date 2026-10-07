# ImageProcessor

C++ 기반의 CLI 이미지 처리 프로그램입니다.

## 프로젝트 소개

BMP 이미지를 입력받아 다양한 이미지 처리 알고리즘을 적용하고
결과 이미지를 BMP 파일로 저장하는 프로그램입니다.

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

## 실행 방법

./ImageProcessor.exe --input input.bmp --output result.bmp --filter grayscale
./ImageProcessor.exe --input input.bmp --output result.bmp --filter blur
./ImageProcessor.exe --input input.bmp --output result.bmp --filter bright 50
./ImageProcessor.exe --input input.bmp --output result.bmp --filter contrast 50
./ImageProcessor.exe --input input.bmp --output result.bmp --filter horizontal
./ImageProcessor.exe --input input.bmp --output result.bmp --filter vertical
./ImageProcessor.exe --input input.bmp --output result.bmp --filter blur --threshold 100
