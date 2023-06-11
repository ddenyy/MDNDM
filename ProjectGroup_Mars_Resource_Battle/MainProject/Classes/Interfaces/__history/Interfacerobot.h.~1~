#pragma once

class InterfaceRobot
{
public:
    TDummy* rdummy;
    TSphere* sphere;
    TCone* cone;
    TCylinder* cylin1;
    TCylinder* cylin2;

    //InterfaceRobot() = default;

    InterfaceRobot(TDummy* RootDummy)
    {
        rdummy = new TDummy(RootDummy);
        rdummy -> Parent = RootDummy;
        rdummy -> RotationAngle -> X = 270;

        sphere = new TSphere(rdummy);
        sphere -> Parent = rdummy;
        sphere -> Height = 1.5;
        sphere -> Width = 0.65;
        sphere -> Depth = 0.35;
        sphere -> Position -> Y -= 0.27;
        sphere -> SubdivisionsAxes = 36;

        cone = new TCone(rdummy);
        cone -> Parent = rdummy;
        cone -> Height = 0.7;
        cone -> Width = 0.5;
        cone -> Depth = 0.4;
        cone -> Position -> Y += 0.65;
        cone -> SubdivisionsAxes = 36;

        cylin1 = new TCylinder(rdummy);
        cylin1 -> Parent = rdummy;
        cylin1 -> RotationAngle -> X = -270;
        cylin1 -> RotationAngle -> Z = 27;
        cylin1 -> Position -> Y -= 0.27;
        cylin1 -> Height = 0.035;
        cylin1 -> Width = 1.3;
        cylin1 -> Depth = 1.4;
        cylin1 -> SubdivisionsAxes = 36;

        cylin2 = new TCylinder(rdummy);
        cylin2 -> Parent = rdummy;
        cylin2 -> RotationAngle -> X = -270;
        cylin2 -> RotationAngle -> Z = -27;
        cylin2 -> Position -> Y -= 0.27;
        cylin2 -> Height = 0.035;
        cylin2 -> Width = 1.3;
        cylin2 -> Depth = 1.4;
        cylin2 -> SubdivisionsAxes = 36;
    }

    void set_position(float new_x, float new_y, float new_z)
    {
        rdummy -> Position -> X = new_x;
        rdummy -> Position -> Y = new_y;
        rdummy -> Position -> Z = new_z;
    }

    void set_material(TLightMaterialSource* Material)
    {
        sphere -> MaterialSource = Material;
        cone -> MaterialSource = Material;
        cylin1 -> MaterialSource = Material;
        cylin2 -> MaterialSource = Material;
    }
};
