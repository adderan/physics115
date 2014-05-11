import java.lang.Math;


class OrbitData extends Data {
	
	double energy(double[] x, double[] v) {
		double rmag = Math.sqrt(x[0]*x[0] + x[1]*x[1]);
		double vmag = Math.sqrt(v[0]*v[0] + v[1]*v[1]);
		return vmag*vmag/2 - 1/rmag;
	}
	
	double[] F(double[] x) {
		double[] force = new double[x.length];
		force[0] = -x[0]/Math.abs(x[0]*x[0]*x[0]);
		force[1] = -x[1]/Math.abs(x[1]*x[1]*x[1]);
		return force;
	}
	void derivs(double t, double[] x, double[] dxdt) {} //does nothing in this case
}
	
public class Orbit {
	public static void main(String[] args) {
		System.out.println("   Time    x     Vx      y      Vy     energy");
		double[] x = new double[2];
		double[] v = new double[2];
		x[1] = 1;
		v[0] = 1;
		double tn = 2*Math.PI;
		double h = 0.02;
		VelocityVerlet vv = new VelocityVerlet();
		vv.velocityVerlet(h, x, v, 0, tn, new OrbitData());
	}
	
}

