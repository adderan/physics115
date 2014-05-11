import java.lang.Math;

public class AnharmonicForce extends Force {
	
	double force(double y) {
		return -y - y*y - y*y*y;
	}
}
