import ev3dev.sensors.Button;

public class HelloWorld {
	public static void main(final String[] args) {
		// initialize first to prevent race conditions
		Button button = new Button();

		System.out.println("Hello World!");

		// access of a static class via an instance reference
		// Button.waitForAnyPress();
		button.waitForAnyPress();

		System.out.println("Button pressed");
	}
}
