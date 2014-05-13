import java.lang.Math;

public class PositionVerlet {
	
	void positionVerlet(double h, double[] x, double[] v, Force f) {
		int N = x.length;
		for(int i = 0; i < N; i++) {
			x[i] += 0.5*h*v[i];
		}
		v[0] += h * (f.force(x[0] - x[1]) - f.force(x[N-1] - x[0]));
	
		for(int i = 1; i < N-1; i++) {
			v[i] += h * (f.force(x[i] - x[i+1]) - f.force(x[i-1] - x[i]));
		}
		v[N-1] += h * (f.force(x[N-1] - x[0]) - f.force(x[N-2] - x[N-1]));
		
		for(int i = 0; i < N; i++) {
			x[i] += 0.5 * h * v[i];
		}
	}
}
