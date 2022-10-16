#include<iostream>
using namespace std;
class shape
{
    public:
        double x;
        double y;
        double area;
        void get_info()
        {
            cin >> x >> y;
        }
        virtual void show_data() = 0;

};
class rectangle : public shape

{
    public:
        void show_data()
        {
            area = x*y;
            cout << "Area of Rectangle : "<< area;
        }
};

class triangle:public shape
{
public:
    void show_data()
    {
        area = 0.5*x*y;
        cout<<"\nArea of Triangle : " << area;
    }
};
int main()
{
    rectangle r1;
    triangle t1;

    cout << "Rectangle:";

    r1.get_info();

    cout << endl << "Triangle:";

    t1.get_info();
    r1.show_data();
    t1.show_data();
}
