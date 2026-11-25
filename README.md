# OpenGL Shader Projects

A series of small, self-contained OpenGL + GLSL projects, built while learning modern OpenGL
(C++, GLFW, glad, glm, stb_image, GLSL 330 core). Each project focuses on one shader technique.

See [PROJECT_PLAN.md](PROJECT_PLAN.md) for the full roadmap.

## Projects

| # | Project | Technique | Status |
|---|---------|-----------|--------|
| 01 | [Waving Flag](01_WavingFlag) | Grid mesh + vertex shader displacement | In progress |
| 02 | Flashlight Reveal | Mouse-driven fragment mask | Planned |
| 03 | Scene Transitions | Multi-texture blending, noise dissolve | Planned |
| 04 | Sprite Sheet Animator | UV offset/scale animation | Planned |
| 05 | Click Ripples | UV distortion from uniform arrays | Planned |

Tiers 1–3 (3D, lighting, model loading) are listed in the plan.

## Build & run

1. Open `Shader Personal Projects.sln` in Visual Studio 2022.
2. Pick a project → **Set as Startup Project**, configuration **Debug | x64**.
3. Run (F5). All libraries are bundled in `dependencies/`, so nothing else needs installing.

## Layout

```
dependencies/   glad, GLFW (static, vc2022), glm, stb_image — shared by every project
Common/         ShaderClass, VAO, VBO, EBO, Texture helpers — shared by every project
NN_ProjectName/ one Visual Studio project per idea
  main.cpp
  Resources/Shaders/   .vert / .frag
  Resources/Textures/
```

## Adding a new project

1. Copy `01_WavingFlag/WavingFlag.vcxproj` into a new `NN_ProjectName/` folder and rename it.
2. In the copy, give it a new `<ProjectGuid>` and `<ProjectName>`, and update the `main.cpp` / shader file entries.
3. Add it to the solution (**Add → Existing Project**).

Include and library paths are relative (`..\dependencies`, `..\Common`), so they work unchanged.
