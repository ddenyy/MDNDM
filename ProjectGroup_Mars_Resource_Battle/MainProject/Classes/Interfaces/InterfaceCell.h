#pragma once

class InterfaceCell
{
public:
    TCube* cube;
    InterfaceArtefact * artefact;

    ~InterfaceCell() = default;

	void create_cube(TDummy*& RootDummy)
    {
        cube = new TCube(RootDummy);
        cube -> Parent = RootDummy;
        cube -> Height = 0.25;
        cube -> Depth = 1.95;
        cube -> Width = 1.95;
    }

    void set_size(float new_height, float new_depth, float new_width)
    {
        cube -> Height = new_height;
        cube -> Depth = new_depth;
        cube -> Width = new_width;
    }

    void set_hill(int height_value)
    {
        float new_height = 0.9 * height_value + 0.25;
        cube -> Position -> Y -= (new_height * 0.5 - cube -> Height * 0.5);
        cube -> Height = new_height;
    }

    void set_position(float new_x, float new_y, float new_z)
    {
        cube -> Position -> X = new_x;
        cube -> Position -> Y = new_y;
        cube -> Position -> Z = new_z;
    }

    void set_material(TLightMaterialSource* Material)
    {
        cube -> MaterialSource = Material;
    }

    void set_artefact(string & artefact_type, string form)
    {
        artefact = new InterfaceArtefact;
        artefact -> create_sphere(cube, artefact_type, form);
    }

};

