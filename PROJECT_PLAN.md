# Shader Personal Projects — Roadmap

Scope: only what's covered by
- the OpenGL course (freeCodeCamp / Victor Gordan, https://www.youtube.com/watch?v=45MIykWJ-C4)
- college CG classes (mouse → NDC, line renderer, circles/rects, flags, key toggles, textures)

Each tier unlocks when the matching chapter is done in `Computer graphics class/OpenGL(self)`.
Advanced ideas (framebuffers, post-processing, shadows, compute, raymarching…) come **after** the course is finished.

Stack: GLFW + glad + glm + stb_image, GLSL `#version 330 core` — same as the class solution.
Layout: one VS project per idea in this solution. Reuse `ShaderClass`, `VAO`, `VBO`, `EBO` from OpenGL(self) — copy them into a shared `Common/` folder; don't rewrite them.

---

## Tier 0 — available now
*(Window, Triangle, Index Buffer, Organizing, Shaders, Textures + college classes)*

| # | Project | What it is | Uses | New GLSL bits |
|---|---------|-----------|------|---------------|
| 1 | **Waving Flag** | Your college flag, but as a subdivided grid mesh that waves in the vertex shader, textured with a flag image. | Grid mesh generated in C++ + EBO, `time` uniform, texture | `sin()` in vertex shader |
| 2 | **Flashlight Reveal** | Dark screen; a soft circle of light follows the mouse and reveals a hidden image. Make it a mini "find the hidden object" game (press key when found). | Your mouse → NDC code as a `vec2 mouse` uniform, texture | `distance()`, `smoothstep()` |
| 3 | **Scene Transitions** | Two textures; keys trigger game-style transitions: fade, wipe, circle iris, noise dissolve. | 2 texture units (`tex0`, `tex1`), `progress` uniform driven by time | `mix()`, `step()`, sampling a noise texture |
| 4 | **Sprite Sheet Animator** | Load a sprite sheet, play a flipbook animation, arrow keys switch rows (idle/run/jump), +/- changes speed. | UV offset/scale uniforms, `GL_NEAREST` filtering, alpha blending | `floor()`, `fract()` |
| 5 | **Click Ripples** | Click anywhere on an image → water ripples spread from that point and fade out. Up to 8 ripples at once. | Mouse click → uniform array of (pos, startTime) | UV distortion with `sin(dist * k - time)` |

**Start with #1** — it builds directly on your flag classwork and is a good first GIF for the portfolio.

---

## Tier 1 — after "Going 3D" + "Camera"
*(model/view/projection matrices, depth test, WASD + mouse camera)*

| # | Project | What it is |
|---|---------|-----------|
| 6 | **Mini Solar System** | Sun, planets, moons orbiting via parent→child matrix multiplication. Keys speed up/slow down time, number keys snap camera to a planet. Sphere mesh generated in C++ (extends your circle code). |
| 7 | **Heightmap Terrain** | Grid mesh whose vertex shader reads a grayscale heightmap texture to raise vertices; color by height (water → grass → rock → snow). Fly over it with the camera. |
| 8 | **Wobbly Blob** | Sphere whose vertices wobble with layered `sin()` over time; mouse distance pushes the surface in. Good "playful" piece. |

---

## Tier 2 — after "Lighting", "Specular Maps", "Types of Light"

| # | Project | What it is |
|---|---------|-----------|
| 9 | **Horror Corridor** | A small corridor made of textured cubes (diffuse + specular maps). Spotlight attached to the camera = flashlight; F toggles it, flickering point light at the end. Most "game-like" piece in the list. |
| 10 | **Day/Night Terrain** | Upgrade #7: rotating directional light as the sun, ambient + clear color shift from dawn → noon → dusk → night. |
| 11 | **Toon Shader** | Same scene, lighting quantized into 2–4 bands + rim light. Key toggles Phong ↔ Toon side by side. Short project with a clear before/after, which works well in a portfolio. |

---

## Tier 3 — after "Mesh Class" + "Model Loading"

| # | Project | What it is |
|---|---------|-----------|
| 12 | **Hologram / Dissolve FX** | Load a glTF model; effects on keys: hologram (scanlines + edge glow + flicker), noise dissolve with glowing edge, toon. |
| 13 | **Shader Showcase (capstone)** | One app: orbit camera around a loaded model, number keys switch shading mode — Flat, Phong, Toon, Normals view, UV view, Hologram, Dissolve. Pulls together Tiers 0–3 and works as the main portfolio piece. |

---

## Portfolio checklist (per project)
- Short GIF/video (10–15 s) — record with OBS or ShareX.
- README: 1 screenshot, controls, "what I learned" in 3 bullets, the key shader snippet.
- Push the whole solution to GitHub; keep `x64/` and `.vs/` out with a `.gitignore`.

## After the course → next roadmap
Come back once OpenGL(self) reaches Model Loading. Next roadmap will cover framebuffers & post-processing,
shadow mapping, normal mapping, skybox/cubemaps, instancing, raymarching, and compute shaders.
