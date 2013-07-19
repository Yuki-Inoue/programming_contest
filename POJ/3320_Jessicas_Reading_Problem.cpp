#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>

int main(){
    long P;
    scanf(" %ld", &P);

    std::vector<long> book(P);
    long num_ideas;
    {
        std::set<long> ideas;
        for (long i=0; i<P; ++i) {
            scanf(" %ld", &book[i]);
            ideas.insert(book[i]);
        }
        num_ideas = ideas.size();
    }



    std::map<long,long> idea_to_count;
    long kinds_of_idea = 0;
    long start = 0, end = 0;
    long mininum = LONG_MAX;
    while (true) {
        while (kinds_of_idea < num_ideas && end < P)
            if (!idea_to_count[book[end++]]++)
                ++kinds_of_idea;
        if (kinds_of_idea < num_ideas)
            break;
        while (kinds_of_idea == num_ideas)
            if (!--idea_to_count[book[start++]])
                --kinds_of_idea;
        mininum = std::min(mininum, end - start + 1);
    }
    printf("%ld\n", mininum);
}
