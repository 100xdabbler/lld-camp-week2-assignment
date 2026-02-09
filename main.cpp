#include<bits/stdc++.h>
using namespace std;

struct Date {
    int day;
    int month;
    int year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Lesson {
    private:
        int id_; string title_; string contentUrl_; int durationMinutes_;
    public:
        Lesson(int id, string title, string contentUrl, int durationMinutes) : id_(id), title_(title), contentUrl_(contentUrl), durationMinutes_(durationMinutes) {};

        const int getId() const { return id_; }
        const string getTitle() const { return title_; }
        const string getContentUrl() const { return contentUrl_; }
        const int getDurationMinutes() const { return durationMinutes_; }
};

class Module {
    private:
        int id_; string title_; vector<Lesson> lessons_;
    public:
        Module(int id, string title, vector<Lesson> lessons) : id_(id), title_(title), lessons_(lessons) {};

        const int getId() const { return id_; }
        const string getTitle() const { return title_; }
        const vector<Lesson>& getLessons() const { return lessons_; }
        void addLesson(const Lesson& lesson) {
            lessons_.push_back(lesson);
        }

};

class Course {
    private:
        int id_; string title_; string description_; vector<Module> modules_; Instructor instructor_;
    public:
        Course(int id, string title, string description, vector<Module> modules, Instructor instructor) : id_(id), title_(title), description_(description), modules_(modules), instructor_(instructor) {};

        const int getId() const { return id_; }
        const string getTitle() const { return title_; }
        const string getDescription() const { return description_; }
        const vector<Module>& getModules() const { return modules_; }
        void addModule(const Module& module) {
            modules_.push_back(module);
        }
};

class ICourseRepository {
    private:
        vector<Course> courses_;
    public:
        void addCourse(const Course& course) {
            courses_.push_back(course);
        }

        const Course getCourseById(int id) const {
            for (const auto& course : courses_) {
                if (course.getId() == id) {
                    return course;
                }
            }
            throw runtime_error("Course not found");
        }
}

enum class EnrollmentStatus {
    ACTIVE,
    COMPLETED,
    CANCELLED
};

class Enrollment {
    private:
        int id_; Date date_; EnrollmentStatus status_; float progressPercent_;
    public:
        Enrollment(int id, Date date, EnrollmentStatus status, float progressPercent) : id_(id), date_(date), status_(status), progressPercent_(progressPercent) {};

        const int getId() const { return id_; }
        const Date getDate() const { return date_; }
        const EnrollmentStatus getStatus() const { return status_; }
        const float getProgressPercent() const { return progressPercent_; }

        void markLessonCompleted() {
            status_ = EnrollmentStatus::COMPLETED;
            progressPercent_ = 100.0f;
        }
};

class User {
    private:
        int id_; string name_; string email_;
    public:
        User(int id, string name, string email) : id_(id), name_(name), email_(email) {};
        
        const int getId() const { return id_; }
        const string getName() const { return name_; }
        const string getEmail() const { return email_; }
};

class Instructor: public User {
    public:
        Instructor(int id, string name, string email) : User(id, name, email) {};

};

class Student: public User {
    private:
        vector<Enrollment> enrollments_;
    public:
        Student(int id, string name, string email) : User(id, name, email) {};
        const vector<Enrollment> getEnrollments() const { return enrollments_; }
        void addEnrollment(const Enrollment& enrollment) {
            enrollments_.push_back(enrollment);
        }
}