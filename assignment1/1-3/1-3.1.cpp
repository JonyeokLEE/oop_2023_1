#include <iostream> //iostream 선언
#include <cmath> //cmath 선언

using namespace std; //namespace std 선언
const double PI = 3.14159265; //파이 값 고정선언

float degtorad(double angle) //각도의 단위를 바꾸는 함수
{
    return angle * PI / 180; //라디안으로 변경하는 연산을 거치고 반환
} //degtorad 함수 종료

int main() //main함수
{
    double deg = 0; //각도를 입력받을 변수 선언
    double x = 0, y = 0, z = 0; //좌표 변수 선언

    cout << "Degrees: ";
    cin >> deg; //각도 입력받기

    double rad = degtorad(deg); //라디안으로 바꾸기


    cout << "Coordinate: ";
    cin >> x >> y >> z; //좌표 입력받기

    double T[3][3] = { {-cos(rad), sin(rad), 0},
                       {sin(rad), cos(rad), 0},
                       {0, 0, 0} }; //입력받은 각도를 바탕으로 T행렬 만들기

    double coor[3] = { x, y, z }; //입력받은 좌표를 배열에 입력(행렬로 만들기)
    double res[3] = { 0, 0, 0 }; //결과값을 입력할 배열 선언

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i] += T[i][j] * coor[j];
        }
    } //이중 for문을 이용하여 T행렬과 coor행렬의 곱 연산 실행

    for (int i = 0; i < 3; i++)
        cout << round(res[i]) << " "; //결과값 출력(반올림하는 round()함수 사용)

    return 0; //0의 반환
} //main함수 종료
