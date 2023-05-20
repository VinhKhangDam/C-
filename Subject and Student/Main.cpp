#include "Subject.cpp"
#include "Student.cpp"

int main()
{
    vector<Subject> v;
    v.push_back(Subject("Hoang Anh Tien", 2, 5, 30));
    v.push_back(Subject("Tien Anh Hoang", 4, 1, 14));
    v.push_back(Subject("Tien Dai Ca", 12, 4, 2003));

    vector<Student> s;
    s.push_back(Student("72DCHT21", "Tien Dai Ca", v));

    for (int i = 0; i < v.size(); i++)
    {
        s[i].display();
    }
    system("pause");
    return 0;
}