//小问学编程
// https://blog.csdn.net/weixin_43297891/article/details/111235337?ops_request_misc=&request_id=&biz_id=102&utm_term=C++%E4%B9%8B%E7%BB%A7%E6%89%BF%E6%8E%A2&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-5-111235337.142^v90^insert_down1,239^v2^insert_chatgpt
#include<iostream>
using namespace std;

class Point
{
  friend ostream &operator<<(ostream&,Point&);
public:
    Point():x(0),y(0){}
    Point(double xval,double yval)
    {
        x=xval;
        y=yval;
    }
protected:
    double x;
    double y;
};

ostream& operator<<(ostream& os,Point& apoint)
{
    os<<"Point:X:Y:"<<apoint.x<<","<<apoint.y<<"\n";
    return os;
}

//Circle类
class Circle:public Point
{
    friend ostream& operator<<(ostream&,Circle&);
public:
    Circle():Point(),radius(0){}
    Circle(double r,double xval,double yval):Point(xval,yval),radius(r){}
    double area(){return(3.14159*radius*radius);}
protected:
    double radius;
};

ostream& operator<<(ostream& os,Circle& aCircle)
{
    os<<"Circle:radius:"<<aCircle.radius;//是Circle的成员
    os<<aCircle.x;     //x,y是Circle从Point继承而来的成员
    os<<aCircle.y<<"\n";
    return os;
}

//Cylinder类
class Cylinder:public Circle
{
    friend ostream& operator<<(ostream&,Cylinder&);
public:
    Cylinder():Circle(){height=0;}
    Cylinder(double hv,double rv,double xv,double yv):Circle(xv,yv,rv){height=hv;}
    double area(){return 2*Circle::area()+2*3.14159*radius*height;}
protected:
    double height;
};

ostream& operator<<(ostream& os,Cylinder& acylinder)
{
        os<<"Cylinder dimensions:";
        os<<"x: "<<acylinder.x;
        os<<" y: "<<acylinder.y;
        os<<" radius: "<<acylinder.radius;
        os<<" height: "<<acylinder.height;
        os<<endl;
        return os;
}

int main()
{
    Point p(2,3);
    Circle c(7,6,5);
    Cylinder cyl(10,11,12,13);

    cout<<p;
    cout<<c;
    cout<<"area circle: "<<c.area()<<endl;

    cout<<cyl;
    cout<<"area cylinder: "<<cyl.area()<<endl;

    cout<<"area cylinder base is: "
    <<cyl.Circle::area()<<endl;
    return 0;
}

