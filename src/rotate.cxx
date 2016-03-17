#include <print_container.h>
#include <algorithm>
#include <vector>

template <typename Container>
void insertion_sort(Container& c)
{
    for (auto it = c.begin(); it != c.end(); ++it) {
        auto first_larger_it = std::upper_bound(c.begin(), it, *it);
        std::rotate(first_larger_it, it, it + 1);
    }
}

int main()
{
    std::vector<int> empty;
    std::vector<int> one{ 1 };
    std::vector<int> few{ 1, 3, 2 };
    std::vector<int> many{ 3, 2, 4, 1, 5 };

    auto print_sort_print = [](auto& container) {
        print_container(container, "initially:            ");
        insertion_sort(container);
        print_container(container, "after insertion_sort: ");
    };

    print_sort_print(empty);
    print_sort_print(one);
    print_sort_print(few);
    print_sort_print(many);
}
