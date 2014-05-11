import java.lang.Math;


class AnharmonicData extends Data {
	void derivs(double t, double[] x, double[] dxdt) {
		dxdt[0] = x[1];
		dxdt[1] = -(x[0]*x[0]*x[0]);
	}
	double[] F(double[] x) {
		double[] force = new double[1];
		force[0] = (-1)*x[0]*x[0]*x[0];
		return force;
	}
	double energy(double[] x, double[] v) {
		return v[0]*v[0]/2 + x[0]*x[0]*x[0]*x[0]/4;
	}
}
public class Anharmonic {
	
	
	public static void main(String[] args) {
		double tn = 10*2*Math.PI;
		double h = 0.02*Math.PI;
		RK2 rk = new RK2();
		//rk.runRK2(h, 0.0, 1.0, tn);
		
		double[] v = new double[1];
		double[] x = new double[1];
		v[0] = 1;
		x[0] = 0;
		System.out.println("   Time      x      p     energy");
		VelocityVerlet vv = new VelocityVerlet();
		vv.velocityVerlet(h, x, v, 0, tn, new AnharmonicData());
		
	}
}

	
	
	
			
			
		
		
		
		