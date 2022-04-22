#include <iostream>
#include <iomanip>
#include <math.h>

class LoadingBar
{
    public:
    LoadingBar(size_t total, bool printWidthAdd=true, bool printOnSameLine=true, size_t printStepSize=1) : totalCount{total}, addPrint{printWidthAdd}, stepSize{printStepSize}
    {
        if(!printOnSameLine)
        {
            lineStart = 0;
            lineEnd = '\n';
        }
    };
    ~LoadingBar() {std::cout << std::endl << std::flush;};
    size_t add(size_t number=1){count+=number; if(addPrint) print(); return count;};
    void print()
    {
        float progress = (static_cast<float>(count)/totalCount)*100;
        std::cout << lineStart << std::setprecision(2) << std::fixed << std::string(static_cast<size_t>(round(progress/stepSize)), '|') << " " << progress << "%" << lineEnd << std::flush;
    }

    private:
    size_t totalCount;
    size_t count{0};
    size_t stepSize{1};
    bool addPrint{false};
    char lineStart = '\r';
    char lineEnd = '\r';
};
