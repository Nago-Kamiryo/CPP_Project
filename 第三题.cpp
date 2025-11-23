#include <iostream>
#include <string>
//李俊尚原创代码，用于联系类的继承，以宿舍楼教学楼为例
class Building {
protected:
    int floors;        // 楼层数
    int rooms;         // 房间数
    double area;       // 总面积
public:
    Building(int f = 0, int r = 0, double a = 0)
        : floors(f), rooms(r), area(a) {}
    void setFloors(int f) { floors = f; }
    void setRooms(int r) { rooms = r; }
    void setArea(double a) { area = a; }

    int getFloors() const { return floors; }
    int getRooms() const { return rooms; }
    double getArea() const { return area; }
    //虚函数用来实现后面的多态
    virtual void showInfo() const {
        std::cout << "楼层数: " << floors
                  << "  房间数: " << rooms
                  << "  总面积: " << area << " 平方米\n";
    }
};
// 教学楼类
class TeachBuilding : public Building {
private:
    int classrooms;  // 教室数量
public:
    TeachBuilding(int f = 0, int r = 0, double a = 0, int c = 0)
        : Building(f, r, a), classrooms(c) {}

    void setClassrooms(int c) { classrooms = c; }
    int getClassrooms() const { return classrooms; }

    void showInfo() const override {
        std::cout << "[教学楼信息]\n";
        Building::showInfo();
        std::cout << "教室数: " << classrooms << "\n\n";
    }
};
// 宿舍楼类
class DormBuilding : public Building {
private:
    int dorms;       // 宿舍数量
    int students;    // 可容纳学生总数
public:
    DormBuilding(int f = 0, int r = 0, double a = 0, int d = 0, int s = 0)
        : Building(f, r, a), dorms(d), students(s) {}

    void setDorms(int d) { dorms = d; }
    void setStudents(int s) { students = s; }

    void showInfo() const override {
        std::cout << "[宿舍楼信息]\n";
        Building::showInfo();
        std::cout << "宿舍数: " << dorms
                  << "  可容纳学生: " << students << " 人\n\n";
    }
};

int main() {
    TeachBuilding t1(5, 50, 3000.0, 20);
    DormBuilding d1(6, 120, 5000.0, 60, 480);

    t1.showInfo();
    d1.showInfo();

    return 0;
}
