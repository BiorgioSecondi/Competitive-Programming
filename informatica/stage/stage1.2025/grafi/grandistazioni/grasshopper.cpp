// NOTE: it is recommended to use this even if you don't understand the following code.
#include <cassert>
#include <iostream>

using namespace std;
// input data
int N;

int main() {
    // uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> N;
    int grasshopper_x = 0, grasshopper_y = 0;
    do {
        int trap_x = 2, trap_y = 2;

        // insert your code here

        cout << trap_x << " " << trap_y << endl;
        cout.flush();

        cin >> grasshopper_x >> grasshopper_y;
        if (grasshopper_x == -1 && grasshopper_y == -1) {
            break;
        }
    } while (true);

    return 0;
}
