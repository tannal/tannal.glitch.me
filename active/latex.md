# inbox

git clone https://github.com/wojtask/clrs4e-solutions

sudo apt install texlive-pstricks texlive-latex-extra texlive-fonts-extra latexmk
chmod +x util/install_fonts.sh && sudo util/install_fonts.sh

latexmk -pdf -file-line-error -halt-on-error -interaction=nonstopmode clrs4e-solutions.tex


$$
f(x) = \int_{-\infty}^\infty
    \hat{f}(\xi) \, e^{2 \pi i \xi x}
    \, d\xi
$$


<math display="block" class="tml-display" style="display:block math;">
  <semantics>
    <mrow>
      <msub>
        <mo movablelimits="false">∮</mo>
        <mi>C</mi>
      </msub>
      <mover>
        <mi>B</mi>
        <mo stretchy="false" style="transform:scale(0.75) translate(10%, 30%);">→</mo>
      </mover>
      <mo>∘</mo>
      <mrow>
        <mi mathvariant="normal">d</mi>
      </mrow>
      <mover>
        <mi>l</mi>
        <mo stretchy="false" style="transform:scale(0.75) translate(10%, 30%);">→</mo>
      </mover>
      <mo>=</mo>
      <msub>
        <mi>μ</mi>
        <mn>0</mn>
      </msub>
      <mrow>
        <mo fence="true" form="prefix">(</mo>
        <msub>
          <mi>I</mi>
          <mtext>enc</mtext>
        </msub>
        <mo>+</mo>
        <msub>
          <mi>ε</mi>
          <mn>0</mn>
        </msub>
        <mfrac>
          <mrow>
            <mi mathvariant="normal">d</mi>
          </mrow>
          <mrow>
            <mrow>
              <mi mathvariant="normal">d</mi>
            </mrow>
            <mi>t</mi>
          </mrow>
        </mfrac>
        <msub>
          <mo movablelimits="false">∫</mo>
          <mi>S</mi>
        </msub>
        <mrow>
          <mover>
            <mi>E</mi>
            <mo stretchy="false" style="transform:scale(0.75) translate(10%, 30%);">→</mo>
          </mover>
          <mo>∘</mo>
          <mover>
            <mi>n</mi>
            <mo stretchy="false" class="tml-xshift" style="math-style:normal;math-depth:0;">^</mo>
          </mover>
        </mrow>
        <mspace width="0.2778em"></mspace>
        <mrow>
          <mi mathvariant="normal">d</mi>
        </mrow>
        <mi>a</mi>
        <mo fence="true" form="postfix">)</mo>
      </mrow>
    </mrow>
    <annotation encoding="application/x-tex">