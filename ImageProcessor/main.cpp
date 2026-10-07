/**
 * @file main.cpp
 * @brief ImageProcessor 진입점 — 지원자가 작성해야 할 파일입니다.
 *
 * BMP 입출력과 커맨드라인 파싱은 제공된 코드가 처리합니다.
 * 본 과제에서 작성해야 할 것은 단 하나입니다:
 *
 *     ▶ 이미지 처리 필터 2개 이상 구현 + main 의 TODO 위치에 연결
 *
 * 또한 일관된 컨벤션과 예외 처리, 메모리 안정성도 함께 평가됩니다.
 */

#include "BmpParser.h"
#include "CommandLineParser.h"
#include "ImageBuffer.h"
#include "Exceptions.h"

#include <iostream>


// TODO: 본인이 구현한 필터 헤더를 include 하세요.
#include "GrayscaleFilter.h"
#include "BrightnessFilter.h"
#include "ContrastFilter.h"
#include "ThresholdFilter.h"
#include "BlurFilter.h"
#include "FlipFilter.h"



int main(int argc, char* argv[]) {
    try {
        // ── CLI 인자 파싱 (제공된 코드) ─────────────────────────
        const ip::ProgramOptions options = ip::CommandLineParser::parse(argc, argv);

        // ── BMP 로드 (제공된 코드) ──────────────────────────────
        ip::ImageBuffer image = ip::BmpParser::loadFromFile(options.inputPath);
        std::cout << "Loaded: " << image.width() << " x " << image.height() << "\n";


        // ============================================================================
        // ============================================================================

        std::unique_ptr<ip::FilterBase> filter;



        if (options.filterName == "grayscale") {
            filter = std::make_unique<ip::GrayscaleFilter>();
        }
        else if (options.filterName == "blur") {
            filter = std::make_unique<ip::BlurFilter>();

        }
        else if (options.filterName == "bright") {
            filter = std::make_unique<ip::BrightnessFilter>(
                options.brightness
            );
        }
        else if (options.filterName == "contrast") {
            filter = std::make_unique<ip::ContrastFilter>(
                options.contrast
            );
        }
        else if (options.filterName == "horizontal") {
            filter = std::make_unique<ip::FlipFilter>(
                ip::FlipFilter::Direction::Horizontal
            );
        }
        else if (options.filterName == "vertical") {
            filter = std::make_unique<ip::FlipFilter>(
                ip::FlipFilter::Direction::Vertical
            );
        }
        else {
            throw ip::FilterError (
                "Unknown filter: " + options.filterName
            );
        }

        filter->apply(image);   



        // 두 번째 파라미터
        if (!options.secondFilterName.empty()) {

            if (options.secondFilterName == "threshold") {
                filter = std::make_unique<ip::ThresholdFilter>(
                    options.threshold
                );

                filter->apply(image);
            }
            else {
                throw ip::FilterError(
                    "Unknown filter: " + options.filterName
                );
            }

        }


        // ── BMP 저장 (제공된 코드) ──────────────────────────────
        ip::BmpParser::saveToFile(options.outputPath, image);
        std::cout << "Saved:  " << options.outputPath << "\n";
        return 0;

    }


// ===========================================================
// ======================== try 문 끝 ========================
// ===========================================================




    catch (const ip::ArgumentError& e) {
        std::cerr << e.what() << "\n\n";
        ip::CommandLineParser::printUsage(argc > 0 ? argv[0] : "ImageProcessor");
        return 4;
    }
    catch (const ip::BmpParseError& e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    catch (const ip::FilterError& e) {
        std::cerr << e.what() << std::endl;
        return 3;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }



}
