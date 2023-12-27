#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

#include "image_enhancement.h"

using std::chrono::high_resolution_clock;

float MyTimeOutput(const std::string &str, const high_resolution_clock::time_point &start_time,
                   const high_resolution_clock::time_point &end_time) {
    float computing_time =
            std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
    std::cout << str << computing_time << "ms" << std::endl;
    return computing_time;
}

void check_fastest_algorithm(float &fastest_time, std::string &fastest_algorithm, float algo_time,
                             const std::string &algo_name) {
    if (algo_time < fastest_time) {
        fastest_time = algo_time;
        fastest_algorithm = algo_name;
    }
}

int main(int argc, char **argv) {
    cv::Mat src = cv::imread(argv[1], 1);

    if (src.empty()) {
        std::cout << "Can't read image file." << std::endl;
        return -1;
    }

    high_resolution_clock::time_point start_time, end_time;
    float fastest_time;
    std::string fastest_algorithm = "";

    start_time = high_resolution_clock::now();
    cv::Mat AINDANE_dst;
    AINDANE(src, AINDANE_dst);
    end_time = high_resolution_clock::now();
    float aindane_time = MyTimeOutput("AINDANE处理时间: ", start_time, end_time);
    fastest_time = aindane_time;
    fastest_algorithm = "AINDANE处理时间";

    start_time = high_resolution_clock::now();
    cv::Mat WTHE_dst;
    WTHE(src, WTHE_dst);
    end_time = high_resolution_clock::now();
    float wthe_time = MyTimeOutput("WTHE处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, wthe_time, "WTHE处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat GCEHistMod_dst;
    GCEHistMod(src, GCEHistMod_dst);
    end_time = high_resolution_clock::now();
    float gceh_time = MyTimeOutput("GCEHistMod处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, gceh_time, "GCEHistMod处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat LDR_dst;
    LDR(src, LDR_dst);
    end_time = high_resolution_clock::now();
    float ldr_time = MyTimeOutput("LDR处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, ldr_time, "LDR处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat AGCWD_dst;
    AGCWD(src, AGCWD_dst);
    end_time = high_resolution_clock::now();
    float agcwd_time = MyTimeOutput("AGCWD处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, agcwd_time, "AGCWD处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat AGCIE_dst;
    AGCIE(src, AGCIE_dst);
    end_time = high_resolution_clock::now();
    float agcie_time = MyTimeOutput("AGCIE处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, agcie_time, "AGCIE处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat IAGCWD_dst;
    IAGCWD(src, IAGCWD_dst);
    end_time = high_resolution_clock::now();
    float iagcwd_time = MyTimeOutput("IAGCWD处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, iagcwd_time, "IAGCWD处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat Ying_dst;
    Ying_2017_CAIP(src, Ying_dst);
    end_time = high_resolution_clock::now();
    float ying_time = MyTimeOutput("Ying处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, ying_time, "Ying处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat CEusingLuminanceAdaptation_dst;
    CEusingLuminanceAdaptation(src, CEusingLuminanceAdaptation_dst);
    end_time = high_resolution_clock::now();
    float cela_time = MyTimeOutput("CEusingLuminanceAdaptation处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, cela_time, "CEusingLuminanceAdaptation处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat adaptiveImageEnhancement_dst;
    adaptiveImageEnhancement(src, adaptiveImageEnhancement_dst);
    end_time = high_resolution_clock::now();
    float aie_time = MyTimeOutput("adaptiveImageEnhancement处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, aie_time, "adaptiveImageEnhancement处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat JHE_dst;
    JHE(src, JHE_dst);
    end_time = high_resolution_clock::now();
    float jhe_time = MyTimeOutput("JHE处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, jhe_time, "JHE处理时间");

    start_time = high_resolution_clock::now();
    cv::Mat SEF_dst;
    SEF(src, SEF_dst);
    end_time = high_resolution_clock::now();
    float sef_time = MyTimeOutput("SEF处理时间: ", start_time, end_time);
    check_fastest_algorithm(fastest_time, fastest_algorithm, sef_time, "SEF处理时间");

//    std::vector<float> algos_running_time = {aindane_time, wthe_time, gceh_time, ldr_time, agcwd_time, agcie_time,
//                                             iagcwd_time, ying_time, aie_time, jhe_time, sef_time};
//    std::sort(algos_running_time.begin(), algos_running_time.end());
    std::cout << "Fastest Algorithm is: " << fastest_algorithm << "with time of: " << fastest_time << std::endl;

    // cv::imshow("src", src);
    // cv::imshow("AINDANE_dst", AINDANE_dst);
    // cv::imshow("WTHE_dst", WTHE_dst);
    // cv::imshow("GCEHistMod_dst", GCEHistMod_dst);
    // cv::imshow("LDR_dst", LDR_dst);
    // cv::imshow("AGCWD_dst", AGCWD_dst);
    // cv::imshow("AGCIE_dst", AGCIE_dst);
    // cv::imshow("IAGCWD_dst", IAGCWD_dst);
    // cv::imshow("Ying_dst", Ying_dst);
    // cv::imshow("CEusingLuminanceAdaptation_dst", CEusingLuminanceAdaptation_dst);
    // cv::imshow("adaptiveImageEnhancement_dst", adaptiveImageEnhancement_dst);
    // cv::imshow("JHE_dst", JHE_dst);
    // cv::imshow("SEF_dst", SEF_dst);

    cv::waitKey();
    return 0;
}