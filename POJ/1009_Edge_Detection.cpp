#include <iostream>

#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>

typedef std::pair<int,long> ImageElement;
typedef std::deque<ImageElement> ImageFormat;

static const ImageElement terminalElement(0,0);

class ElementWriter {
    bool first;
    ImageElement buffer;
public:
    ElementWriter() : first(true) {}
    void write(const ImageElement &element) {
        if (first) {
            first = false;
            buffer = element;
        }
        else if (!element.second || element.first == buffer.first)
            buffer.second += element.second;
        else {
            printf("%d %ld\n", buffer.first, buffer.second);
            buffer = element;
        }
    }
    void finish() {
        printf("%d %ld\n", buffer.first, buffer.second);
        puts("0 0");
        first = true;
    }
};


class Solver {
    long width;
    std::vector<ImageFormat> lines;
    ElementWriter element_writer;

    ImageElement current_element;

public:
    explicit Solver (long width_) :
    width(width_), lines(3) {
        charge_current_element();
    }

    void solve() {
        printf("%ld\n", width);
        readline(lines[0]);
        this->lines[1] = lines[0];
        while (readline_with_skipping()) {
            writeLineMaxDiff();
            lines[0].swap(lines[1]);
            lines[1].swap(lines[2]);
        }
        lines[2] = lines[1];
        writeLineMaxDiff();
        element_writer.finish();
    }
private:
    bool readline_with_skipping();
    void readline(ImageFormat &emptyline);
    void charge_current_element() {
        std::cin >> current_element.first >> current_element.second;
    }

    void writeLineMaxDiff();
};


// used when there can always be line read.
// current_element must always be existed
// and always non null sized.
void Solver::readline(ImageFormat &line){

    long remaining_space = width;
    while (remaining_space > 0) {
        if (current_element.second > remaining_space) {
            line.push_back
            (ImageElement
             (current_element.first, remaining_space));
            current_element.second -= remaining_space;
            remaining_space = 0;
        }
        else {
            line.push_back(current_element);
            remaining_space -= current_element.second;
            charge_current_element();
        }
    }

    // ease the maxdiffprint
    line.front().second++;
    line.back().second++;
}

bool Solver::readline_with_skipping() {
    if (current_element == terminalElement) {
        return false;
    }

    if (lines[0].size() == 1 &&
        lines[1].size() == 1 &&
        lines[0][0].first == lines[1][0].first &&
        current_element.first == lines[0][0].first &&
        current_element.second >= width)
    {
        element_writer.write
        (ImageElement
         (0, current_element.second / width * width));

        current_element.second %= width;
        if (!current_element.second)
            charge_current_element();
        return readline_with_skipping();
    }

    lines[2].clear();
    readline(lines[2]);

    return true;
}

static void normalize_remaining(ImageFormat &remaining){
    if (!remaining.front().second)
        remaining.pop_front();
}

static void read_column(std::vector<int> &col, std::vector<ImageFormat> &remainings){
    for (int i=0; i<3; ++i) {
        col[i] = remainings[i].front().first;
        --remainings[i].front().second;
        normalize_remaining(remainings[i]);
    }
}

void Solver::writeLineMaxDiff() {
    std::vector<std::vector<int> > line_cols(3, std::vector<int>(3));
    std::vector<ImageFormat> remainings = lines;
    read_column(line_cols[0], remainings);
    read_column(line_cols[1], remainings);
    while (!remainings[0].empty()) {
        if (line_cols[0][0] == line_cols[1][0] &&
            line_cols[0][1] == line_cols[1][1] &&
            line_cols[0][2] == line_cols[1][2] &&
            line_cols[0][0] == remainings[0].front().first &&
            line_cols[0][1] == remainings[1].front().first &&
            line_cols[0][2] == remainings[2].front().first) {

            long min_length = remainings[0].front().second;
            for (int i=1; i<3; ++i)
                min_length = std::min(min_length, remainings[i].front().second);

            const int max_diff =
            std::max
            (abs(line_cols[0][0] - line_cols[0][1]),
             abs(line_cols[0][1] - line_cols[0][2]));

            element_writer.write(ImageElement(max_diff, min_length));

            for (int i=0; i<3; ++i) {
                remainings[i].front().second -= min_length;
                normalize_remaining(remainings[i]);
            }
            continue;
        }

        read_column(line_cols[2], remainings);

        int max_diff = 0;
        for (int i=0; i<3; ++i) for(int j=0; j<3; ++j) if (!(i==1 && j==1))
            max_diff = std::max(max_diff, abs(line_cols[1][1] - line_cols[i][j]));

        element_writer.write(ImageElement(max_diff, 1));

        line_cols[0].swap(line_cols[1]);
        line_cols[1].swap(line_cols[2]);
    }
}

int main(){
    long width;
    while (std::cin >> width && width)
        Solver(width).solve();
    printf("0\n");
}
