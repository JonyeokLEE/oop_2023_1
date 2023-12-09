#include <iostream> //iostream ����
#include <cmath> //cmath ����

using namespace std; //namespace std ����
const double PI = 3.14159265; //���� �� ��������

float degtorad(double angle) //������ ������ �ٲٴ� �Լ�
{
    return angle * PI / 180; //�������� �����ϴ� ������ ��ġ�� ��ȯ
} //degtorad �Լ� ����

int main() //main�Լ�
{
    double deg = 0; //������ �Է¹��� ���� ����
    double x = 0, y = 0, z = 0; //��ǥ ���� ����

    cout << "Degrees: ";
    cin >> deg; //���� �Է¹ޱ�

    double rad = degtorad(deg); //�������� �ٲٱ�


    cout << "Coordinate: ";
    cin >> x >> y >> z; //��ǥ �Է¹ޱ�

    double T[3][3] = { {-cos(rad), sin(rad), 0},
                       {sin(rad), cos(rad), 0},
                       {0, 0, 0} }; //�Է¹��� ������ �������� T��� �����

    double coor[3] = { x, y, z }; //�Է¹��� ��ǥ�� �迭�� �Է�(��ķ� �����)
    double res[3] = { 0, 0, 0 }; //������� �Է��� �迭 ����

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i] += T[i][j] * coor[j];
        }
    } //���� for���� �̿��Ͽ� T��İ� coor����� �� ���� ����

    for (int i = 0; i < 3; i++)
        cout << round(res[i]) << " "; //����� ���(�ݿø��ϴ� round()�Լ� ���)

    return 0; //0�� ��ȯ
} //main�Լ� ����
