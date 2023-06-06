#pragma once

class InterfaceArtefact
{
public:
    TSphere * sphere;
    TLightMaterialSource * material;

    void create_sphere(TCube* root_cube, string &artefact_type)
    {
        sphere = new TSphere(root_cube);
        sphere -> Parent = root_cube;
        sphere -> Height = 1;
        sphere -> Width = 1;
        sphere -> Depth = 1;
        sphere -> Position -> Y -= (0.05 + root_cube -> Height * 0.5 + 0.5);
        material = new TLightMaterialSource(root_cube);

        if (artefact_type == "rare") {
            sphere -> Width = 0.8;
	        sphere -> Depth = 0.8;
            material -> Diffuse = 0x00ff0000;
            sphere -> MaterialSource = material;
        }

        if (artefact_type == "usually") {
            sphere -> Width = 0.5;
	        sphere -> Depth = 0.5;
            material -> Diffuse = 0x000000ff;
            sphere -> MaterialSource = material;
        }

        if (artefact_type == "frequent") {
            sphere -> Width = 0.3;
	        sphere -> Depth = 0.3;
            material -> Diffuse = 0x0000ff00;
            sphere -> MaterialSource = material;
        }
    }
};
