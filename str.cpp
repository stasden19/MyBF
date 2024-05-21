#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream in_file("1.bf");
    if (!in_file.is_open()){
        return 1;
    }
    string content((istreambuf_iterator<char>(in_file)), istreambuf_iterator<char>());
    cout << (content[0] + 2);
    int position = 0;
    int lenth = count(content.begin(), content.end(), '>');
    int* poiters = (int*)malloc(lenth * sizeof(int));
    for (size_t i = 0; i < content.length(); i++)
    {
        switch (content[i])
        {
        case '>':
            position += 1;
            break;
        case '<':
            position = position == 0 ? 0 : position - 1;
            break;
        case '+':
            if (0 < (content[i + 1]) &  (int)(content[i + 1])< 10){
                poiters[position] += (content[i + 1]);
                i++;
                break;
            }
            else
                {poiters[position] += 1;}
            break;
        case '-':
            poiters[position] -= 1;
            break;   
        case '.':            
            cout << (char)poiters[position];
            break; 
        case '#':
            poiters[position] = 0;
            break; 
        case ',':
            poiters[position] = content[i + 1];
            i++;
            break;
        default:
            break;  
        }
        
    }
    cout << '\n';
    for (int i = 0; i <= lenth; i++){
        cout << static_cast<int>(poiters[i]) << ' ';
    }
    cout << endl;
    
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
        
    return 0;
}
