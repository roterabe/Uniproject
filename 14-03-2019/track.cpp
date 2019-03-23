#include <iostream>
#include <vector>
using namespace std;

class Segment {
public:
    Segment(const Segment &other) {
        cout << "Segment(&other)" << endl;
        length = other.length;
        rad = other.rad;
    }
    Segment(float l, float r) {
        cout << "Segment(l, r)" << endl;
        if (l < 0){
            cout << "ERROR: negative length!" << endl;
            l = 0;
        }
        if (r < 0){
            cout << "ERROR: negative radius!" << endl;
            r = 0;
        }
        length = l;
        rad = r;
    }

    float getLength() const  {
        return length;
    }

    float getRadius() const  {
        return rad;
    }

    bool isTurn() const {
        return rad > 0;
    }

private:
    float length; //in meters
    float rad; //in meters
};

class Track {
public:
//Does not close track!!
        void add( Segment *s) {
        segments.push_back(s);
    }
    int count() const {
        return segments.size();
    }
    float length()  {
        float length = 0;
        for (auto s:segments) {
            length += s->getLength();
        }
    }
private:
    vector<Segment*> segments;

};


void print(const Segment s){
    cout << s.getLength() << " | " << s.getRadius() << endl;
}


int main(){
    Track t;
    Segment *s1 = new Segment(100, 0);
    Segment s2(10, 10);
    t.add(s1);
    t.add(&s2);
    cout << t.length() << endl;
    //t.add(s1);
    //cout << t.length() << endl;
    //Segment s2(10, 10);
    //Segment s3(50, 0);
    //Segment s4(20, 50);


   /* if(s1.isTurn()){
        cout << "Turn" << endl;
    }
    else {
        cout << "Straigth line" << endl;
    }

    print(s1);
*/
    delete s1;

    return 0;
}