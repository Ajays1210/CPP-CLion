#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// A simple 3D vector class
struct Vec3 {
    double x, y, z;

    Vec3 operator+(const Vec3& other) const { return {x + other.x, y + other.y, z + other.z}; }
    Vec3 operator-(const Vec3& other) const { return {x - other.x, y - other.y, z - other.z}; }
    Vec3 operator*(double t) const { return {x * t, y * t, z * t}; }
    double dot(const Vec3& other) const { return x * other.x + y * other.y + z * other.z; }
    Vec3 normalize() const {
        double len = std::sqrt(x*x + y*y + z*z);
        return {x / len, y / len, z / len};
    }
};

// A simple ray class
struct Ray {
    Vec3 origin;
    Vec3 direction;
};

// A simple sphere class
struct Sphere {
    Vec3 center;
    double radius;
};

// Function to check for ray-sphere intersection
double intersect(const Ray& ray, const Sphere& sphere) {
    Vec3 oc = ray.origin - sphere.center;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - sphere.radius * sphere.radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return -1.0; // No intersection
    } else {
        return (-b - std::sqrt(discriminant)) / (2.0 * a);
    }
}

// Function to calculate color based on intersection
Vec3 get_color(const Ray& ray) {
    Sphere sphere = {{0, 0, -1}, 0.5}; // A sphere at (0,0,-1) with radius 0.5

    double t = intersect(ray, sphere);
    if (t > 0.0) {
        Vec3 hit_point = ray.origin + ray.direction * t;
        Vec3 normal = (hit_point - sphere.center).normalize();

        // Simple light direction (coming from top-right)
        Vec3 light_dir = {1.0, 1.0, -1.0};
        light_dir = light_dir.normalize();

        double light_intensity = std::max(0.0, normal.dot(light_dir));
        Vec3 color = {0.7, 0.3, 0.3}; // A reddish-brown color
        return color * light_intensity;
    }
    // Background color (gradient from blue to white)
    Vec3 unit_direction = ray.direction.normalize();
    double t_bg = 0.5 * (unit_direction.y + 1.0);
    Vec3 white = {1.0, 1.0, 1.0};
    Vec3 sky_blue = {0.5, 0.7, 1.0};
    return white * (1.0 - t_bg) + sky_blue * t_bg;
}

int main() {
    const int width = 256;
    const int height = 256;

    // Open a file to write the PPM image
    std::ofstream file("ray_traced_image.ppm");
    if (!file) {
        std::cerr << "Error: Could not create output file." << std::endl;
        return 1;
    }

    // PPM header
    file << "P3\n" << width << " " << height << "\n255\n";

    // Camera setup
    Vec3 camera_origin = {0, 0, 0};
    Vec3 horizontal = {width, 0, 0};
    Vec3 vertical = {0, height, 0};
    Vec3 lower_left_corner = {-width/2.0, -height/2.0, -1.0};

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            double u = (double)i / (width - 1);
            double v = (double)j / (height - 1);

            Ray ray;
            ray.origin = camera_origin;
            ray.direction = lower_left_corner + horizontal * u + vertical * v;

            Vec3 color = get_color(ray);

            // Convert to 0-255 range and write to file
            int ir = static_cast<int>(255.999 * color.x);
            int ig = static_cast<int>(255.999 * color.y);
            int ib = static_cast<int>(255.999 * color.z);
            file << ir << " " << ig << " " << ib << "\n";
        }
    }

    file.close();
    std::cout << "Image saved to ray_traced_image.ppm" << std::endl;

    return 0;
}