
public class Box {
    int w,h,d;

    Box(int w,int h,int d){
        this.w = w;
        this.h = h;
        this.d = d;
    }

    double volume(){
        double vol = 0;
        vol = w*h*d;
        return vol;
    }
}