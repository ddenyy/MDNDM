#pragma once

class InterfaceArtefact
{
public:
    TCube * cube;
    TSphere * sphere;
    TCylinder * cylin;
    TLightMaterialSource * material;

    string art_form;

    void delete_interface()
    {
        if (art_form == "TCube")
            delete cube;
        if (art_form == "TSphere")
            delete sphere;
        if (art_form == "TCylinder")
            delete cylin;
    }

    void create_sphere(TCube* root_cube, string &artefact_type, string &artefact_form)
    {
        art_form = artefact_form;

        if (artefact_form == "TCube") {
            cube = new TCube(root_cube);
            cube -> Parent = root_cube;
            cube -> Height = 1;
            cube -> Width = 1;
            cube -> Depth = 1;
            cube -> Position -> Y -= (0.05 + root_cube -> Height * 0.5 + 0.5);
            material = new TLightMaterialSource(root_cube);

            if (artefact_type == "rare") {
                cube -> Width = 0.8;
                cube -> Depth = 0.8;
                material -> Diffuse = 0x00ff0000;
                cube -> MaterialSource = material;
            }

            if (artefact_type == "usually") {
                cube -> Width = 0.5;
                cube -> Depth = 0.5;
                material -> Diffuse = 0x000000ff;
                cube -> MaterialSource = material;
            }

            if (artefact_type == "frequent") {
                cube -> Width = 0.3;
                cube -> Depth = 0.3;
                material -> Diffuse = 0x0000ff00;
                cube -> MaterialSource = material;
            }
        }

        if (artefact_form == "TSphere") {
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

        if (artefact_form == "TCylinder") {
            cylin = new TCylinder(root_cube);
            cylin -> Parent = root_cube;
            cylin -> Height = 1;
            cylin -> Width = 1;
            cylin -> Depth = 1;
            cylin -> Position -> Y -= (0.05 + root_cube -> Height * 0.5 + 0.5);
            material = new TLightMaterialSource(root_cube);

            if (artefact_type == "rare") {
                cylin -> Width = 0.8;
                cylin -> Depth = 0.8;
                material -> Diffuse = 0x00ff0000;
                cylin -> MaterialSource = material;
            }

            if (artefact_type == "usually") {
                cylin -> Width = 0.5;
                cylin -> Depth = 0.5;
                material -> Diffuse = 0x000000ff;
                cylin -> MaterialSource = material;
            }

            if (artefact_type == "frequent") {
                cylin -> Width = 0.3;
                cylin -> Depth = 0.3;
                material -> Diffuse = 0x0000ff00;
                cylin -> MaterialSource = material;
            }
        }
    }
};
