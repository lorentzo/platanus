
// marker class for now.
class BSDF
{

  public:

    BSDF() {}

    virtual Vector3d evaluate(
        const Vector3d &normal, 
        const Vector3d &light_direction, 
        const Vector3d &light_color,
        const double &light_intensity
    ) const;
};