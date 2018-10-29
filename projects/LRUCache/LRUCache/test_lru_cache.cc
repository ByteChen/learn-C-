/*
* Copyright 2018 ByteChen. All rights reserved.
*
* Licensed under the BSD 3-Clause License (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     https://opensource.org/licenses/BSD-3-Clause
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "lru_cache.h"
#include <string>
using std::cout;
using std::endl;

// 建立一个Test类，用来测试LRUCache
class Test {
public:
    Test(int value = 0) :m_iData(value) {}

    friend bool operator!=(const Test& lhs, const Test& rhs) {
        return !(lhs.m_iData == rhs.m_iData);
    }

    friend std::ostream& operator<<(std::ostream& os, const Test& rhs) {
        os << rhs.m_iData;
        return os;
    }
private:
    int m_iData;
};

int main() {
    using My_LRU_Cache::LRUCache;
    using std::string;

    cout << "\n====test LRUCache<int, double>=========" << endl;
    LRUCache<int, double> idCache(2);
    idCache.Put(1, 1.1);
    idCache.Put(2, 2.2);
    cout << idCache.Get(1) << endl;
    idCache.Put(3, 3.3);
    cout << "Get(2)： ";
    cout << idCache.Get(2) << endl;
    cout << "Get(3)： ";
    cout << idCache.Get(3) << endl;
    idCache.Put(4, 4.1);
    cout << "Get(1): ";
    cout << idCache.Get(1) << endl;
    cout << "Get(4)： ";
    cout << idCache.Get(4) << endl;
    cout << "Get(3)： ";
    cout << idCache.Get(3) << endl;
    idCache.PrintRecords();

    cout << "\n====test LRUCache<string, string>======" << endl;
    LRUCache<string, string> ssCache(2);
    ssCache.Put("Mike", "Mike is a boy");
    ssCache.Put("Jack", "Jack is a girl");
    cout << "Get(\"Mike\"): ";
    cout << ssCache.Get("Mike") << endl;
    ssCache.Put("Amy", "Amy is not a girl");
    cout << "Get(\"Jack\"): ";
    cout << ssCache.Get("Jack") << endl;
    cout << "Get(\"Amy\"): ";
    cout << ssCache.Get("Amy") << endl;

    cout << "\n====test LRUCache<int, Test>==========" << endl;
    LRUCache<int, Test> itCache(2);
    itCache.Put(1, Test(1));
    itCache.Put(2, Test(2));
    cout << "Get(1): ";
    cout << itCache.Get(1) << endl;
    itCache.Put(3, Test(3));
    cout << "Get(2): ";
    cout << itCache.Get(2) << endl;
    cout << "Get(3): ";
    cout << itCache.Get(3) << endl;
    // system("pause");
    return 0;
}
