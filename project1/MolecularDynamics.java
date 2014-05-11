import java.lang.Math;

public class MolecularDynamics {
	
	public static void main(String[] args) {
		PositionVerlet pv = new PositionVerlet();
		AnharmonicForce af = new AnharmonicForce();
		MolecularDynamics md = new MolecularDynamics();
		
		int N = 30;
		double h = 0.02;
		
		double[] y = new double[N];
		double[] v = new double[N];
		md.setInitialConditions(y, v, 0.25);
		double tEnd = 1000.0;
		double t = 0.0;
		double temp;
		while(t <= tEnd) {
			pv.positionVerlet(h, y, v, af);
			temp = md.temp(v);
			System.out.println(temp);
			t += h;
		}		
		
		
	}
	
	double temp(double[] v) {
		int N = v.length;
		double avg = 0;
		for(int i = 0; i < N; i++) {
			avg += v[i]*v[i];
		}
		return avg/N;
	}
	void setInitialConditions(double[] y, double[] v, double delta) {
		int N = y.length;
		for(int i = 0; i < N; i++) {
			y[i] = 0;
			v[i] = Math.sin(2*Math.PI*((double)i + delta)/N);
		}
	}
}
			
	