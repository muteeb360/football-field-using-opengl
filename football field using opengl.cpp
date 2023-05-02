#include <gl\glut.h>

#include <math.h>

//setting up vertices and colors. In 7 index array first 4 values are vertex values and next 3 are for colors
float hr_top_rect_out[4] = { -1.0,1.0,0.99,0.7 };
float hr_top_rect[7] = { -0.99,0.99,0.72,0.97,0.29,0.67,0.77 };
float hr_bottom_rect_out[4] = { -1.0,1.0,-0.99,-0.7 };
float hr_bottom_rect[7] = { -0.99,0.99,-0.72,-0.97,.75,0.31,0.3 };
float vr_left_rect_out[4] = { -0.8,-1.0,-0.7,0.7 };
float vr_left_rect[7] = { -0.81,-0.99,-0.69,0.69,0.96,0.58,0.27 };
float vr_right_rect_out[4] = { 0.8,1.0,-0.7,0.7 };
float vr_right_rect[7] = { 0.81,0.99,-0.69,0.69,0.3,0.5,0.74 };
float mid_brown_rect[7] = { -0.79,0.79,-0.69,0.69,0.41,0.25,0.17 };
float field_green_rect_out[4] = { -0.7,0.7,-0.5,0.5 };
float field_green_rect[7] = { -0.699,0.699,-0.49,0.49,0.2,0.8,0.39 };
float left_D[4] = { -0.7, -0.4, -0.3, 0.3 };
float right_D[4] = { 0.4, 0.7, -0.3, 0.3 };
float left_goal_space_out[4] = { -0.7,-0.6,-0.2,0.2 };
float left_goal_space_rect[7] = { -0.699,-0.6,-0.2,0.2,1.0,1.0,1.0 };
float right_goal_space_out[4] = { 0.7,0.6,-0.2,0.2 };
float right_goal_space_rect[7] = { 0.699,0.6,-0.2,0.2,1.0,1.0,1.0 };

/*outline function for all the component's outlines
  this function takes an array for the coordinates, check variables checks if the rectangle being
  made is horizontal or vertical,
  color variable checks if the color is to be set grey or black also the line width*/
void outline(float arr[], bool check, bool color) {
	float line_width;
	if (color == 1) {
		glColor3f(0.9f, 0.9f, 0.9f); // Set color to gray
		line_width = 10.0;
	}
	else {
		glColor3f(0.0f, 0.0f, 0.0f);// Set color to black
		line_width = 5.0;
	}

	glLineWidth(line_width); // Set line width

	glBegin(GL_LINE_LOOP);
	if (check == 1) {
		//for horizontal
		glVertex2f(arr[0], arr[2]);

		glVertex2f(arr[1], arr[2]);

		glVertex2f(arr[1], arr[3]);

		glVertex2f(arr[0], arr[3]);
	}
	else {
		//for vertical
		glVertex2f(arr[0], arr[2]);

		glVertex2f(arr[0], arr[3]);

		glVertex2f(arr[1], arr[3]);

		glVertex2f(arr[1], arr[2]);
	}
	glEnd();
}

//function for making filled color rectangles, check sees if rectangle to be made is vertical or horizontal
void rect(float arr[], bool check) {
	glColor3f(arr[4], arr[5], arr[6]);
	glBegin(GL_QUADS);
	if (check == 1) {
		//for horizontal
		glVertex2f(arr[0], arr[2]); // bottom-left vertex
		glVertex2f(arr[1], arr[2]); // bottom-right vertex
		glVertex2f(arr[1], arr[3]); // top-right vertex
		glVertex2f(arr[0], arr[3]); // top-left vertex
	}
	else {
		//for vertical
		glVertex2f(arr[0], arr[2]); // bottom-left vertex
		glVertex2f(arr[0], arr[3]); // bottom-right vertex
		glVertex2f(arr[1], arr[3]); // top-right vertex
		glVertex2f(arr[1], arr[2]); // top-left vertex
	}

	glEnd();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

	// horizontal rectangle top

	//outline
	outline(hr_top_rect_out, 1, 1);

	//inner rectangle
	rect(hr_top_rect, 1);

	// horizontal rectangle bottom

	//outline
	outline(hr_bottom_rect_out, 1, 1);

	//inner rectangle
	rect(hr_bottom_rect, 1);


	// vertical rectangle left

	//outline
	outline(vr_left_rect_out, 0, 1);

	//rectangle
	rect(vr_left_rect, 0);

	// vertical rectangle right

	//outline
	outline(vr_right_rect_out, 0, 1);

	//inner rectangle
	rect(vr_right_rect, 0);

	//middle brown rectangle
	rect(mid_brown_rect, 0);

	//------------------>field code started<---------------------//

	//green rectangle outline

	outline(field_green_rect_out, 0, 0);

	//green rectangle
	rect(field_green_rect, 0);

	//D's

	//left D

	outline(left_D, 0, 0);

	//right D
	outline(right_D, 0, 0);

	//points in D's

	//left
	glColor3f(0.0f, 0.0f, 0.0f); // Set color to black
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glVertex2f(-0.5f, 0.0f);
	glEnd();

	//right
	glColor3f(0.0f, 0.0f, 0.0f); // Set color to black
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glVertex2f(0.5f, 0.0f);
	glEnd();

	//goal space

	//left goal space

	//outline
	outline(left_goal_space_out, 0, 0);

	//inner goal
	rect(left_goal_space_rect, 0);


	//right goal space
	//outline
	outline(right_goal_space_out, 0, 0);

	//inner goal
	rect(right_goal_space_rect, 0);

	//middle line
	glColor3f(0.0f, 0.0f, 0.0f); // Set color to black

	glLineWidth(5.0f); // Set line width

	glBegin(GL_LINES);

	glVertex2f(0.0f, -0.5f);

	glVertex2f(0.0f, 0.5f);

	glEnd();

	//middle circle outline
	glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 360; i++) {

		float angle = i * 3.1415926f / 180.0f;

		float x = 0.1f * cos(angle);

		float y = 0.2f * sin(angle);

		glVertex2f(x, y);

	}

	glEnd();

	double PI = 3.141592653589793238;
	//middle inner green circle
	glColor3f(0.6f, 0.7f, 0.3f); // set color to green
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f); // center of the circle
	for (float angle = 0.0; angle < 3.0 * PI; angle += PI / 16.0) {
		float x = 0.09 * cos(angle);
		float y = 0.19 * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(1000, 500);

	glutCreateWindow("Football match");

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}