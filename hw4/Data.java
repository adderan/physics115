

public abstract class Data {
	
	abstract double[] F(double[] x);
	//abstract double energy(double x, double v);
	abstract double energy(double[] x, double[] v);
	abstract void derivs(double t, double[] x, double[] dxdt);
	
}
	
