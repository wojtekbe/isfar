<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Power_Led">
<packages>
<package name="LZ1">
<text x="0" y="-4.064" size="1.27" layer="25">&gt;NAME</text>
<text x="0" y="-5.588" size="1.27" layer="27">&gt;VALUE</text>
<smd name="5" x="0" y="0" dx="3.2" dy="3.2" layer="1" roundness="100"/>
<polygon width="0.254" layer="1">
<vertex x="1.25" y="2.45"/>
<vertex x="2.45" y="2.45"/>
<vertex x="2.45" y="1.25"/>
<vertex x="1.75" y="1.25"/>
<vertex x="1.25" y="1.68"/>
</polygon>
<polygon width="0.3556" layer="29">
<vertex x="1.25" y="2.45"/>
<vertex x="2.45" y="2.45"/>
<vertex x="2.45" y="1.25"/>
<vertex x="1.75" y="1.25"/>
<vertex x="1.25" y="1.68"/>
</polygon>
<polygon width="0.3556" layer="29">
<vertex x="1.25" y="-2.45"/>
<vertex x="2.45" y="-2.45"/>
<vertex x="2.45" y="-1.25"/>
<vertex x="1.75" y="-1.25"/>
<vertex x="1.25" y="-1.68"/>
</polygon>
<polygon width="0.254" layer="1">
<vertex x="1.25" y="-2.45"/>
<vertex x="2.45" y="-2.45"/>
<vertex x="2.45" y="-1.25"/>
<vertex x="1.75" y="-1.25"/>
<vertex x="1.25" y="-1.68"/>
</polygon>
<polygon width="0.254" layer="1">
<vertex x="-1.25" y="2.45"/>
<vertex x="-2.45" y="2.45"/>
<vertex x="-2.45" y="1.25"/>
<vertex x="-1.75" y="1.25"/>
<vertex x="-1.25" y="1.68"/>
</polygon>
<polygon width="0.3556" layer="29">
<vertex x="-1.25" y="2.45"/>
<vertex x="-2.45" y="2.45"/>
<vertex x="-2.45" y="1.25"/>
<vertex x="-1.75" y="1.25"/>
<vertex x="-1.25" y="1.68"/>
</polygon>
<polygon width="0.254" layer="1">
<vertex x="-1.25" y="-2.45"/>
<vertex x="-2.45" y="-2.45"/>
<vertex x="-2.45" y="-1.25"/>
<vertex x="-1.75" y="-1.25"/>
<vertex x="-1.25" y="-1.68"/>
</polygon>
<polygon width="0.3556" layer="29">
<vertex x="-1.25" y="-2.45"/>
<vertex x="-2.45" y="-2.45"/>
<vertex x="-2.45" y="-1.25"/>
<vertex x="-1.75" y="-1.25"/>
<vertex x="-1.25" y="-1.68"/>
</polygon>
<smd name="4" x="-1.85" y="-2.07" dx="1.2" dy="0.77" layer="1"/>
<smd name="2" x="1.85" y="2.07" dx="1.2" dy="0.77" layer="1"/>
<smd name="1" x="-1.85" y="2.07" dx="1.2" dy="0.77" layer="1"/>
<smd name="3" x="1.85" y="-2.07" dx="1.2" dy="0.77" layer="1"/>
<wire x1="2" y1="2.2" x2="2.2" y2="2" width="0.127" layer="21" curve="90"/>
<wire x1="-2" y1="2.2" x2="-2.2" y2="2" width="0.127" layer="21" curve="-90"/>
<wire x1="-2" y1="-2.2" x2="-2.2" y2="-2" width="0.127" layer="21" curve="90"/>
<wire x1="2" y1="-2.2" x2="2.2" y2="-2" width="0.127" layer="21" curve="-90"/>
<wire x1="-2" y1="2.2" x2="2" y2="2.2" width="0.127" layer="21"/>
<wire x1="2.2" y1="2" x2="2.2" y2="-2" width="0.127" layer="21"/>
<wire x1="2" y1="-2.2" x2="-2" y2="-2.2" width="0.127" layer="21"/>
<wire x1="-2.2" y1="-2" x2="-2.2" y2="2" width="0.127" layer="21"/>
<circle x="0" y="0" radius="1.6" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.6" x2="1.9" y2="1.6" width="0.127" layer="21"/>
<wire x1="1.7" y1="1.8" x2="1.7" y2="1.4" width="0.127" layer="21"/>
<wire x1="1.5" y1="-1.6" x2="1.9" y2="-1.6" width="0.127" layer="21"/>
<wire x1="1.7" y1="-1.4" x2="1.7" y2="-1.8" width="0.127" layer="21"/>
<wire x1="-1.9" y1="-1.6" x2="-1.5" y2="-1.6" width="0.127" layer="21"/>
<wire x1="-1.9" y1="1.6" x2="-1.5" y2="1.6" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="1XDIE">
<wire x1="0.762" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="0" x2="0.762" y2="1.27" width="0.254" layer="94"/>
<wire x1="-1.27" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-1.27" y1="0" x2="-1.27" y2="1.27" width="0.254" layer="94"/>
<wire x1="0.762" y1="-1.27" x2="0.762" y2="1.27" width="0.254" layer="94"/>
<wire x1="0.508" y1="2.032" x2="-0.381" y2="2.921" width="0.1524" layer="94"/>
<wire x1="-0.254" y1="1.27" x2="-1.143" y2="2.159" width="0.1524" layer="94"/>
<polygon width="0.1524" layer="94">
<vertex x="0" y="3.048"/>
<vertex x="-0.762" y="3.302"/>
<vertex x="-0.508" y="2.54"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-0.762" y="2.286"/>
<vertex x="-1.524" y="2.54"/>
<vertex x="-1.27" y="1.778"/>
</polygon>
<text x="-1.524" y="-5.08" size="1.778" layer="95">&gt;NAME</text>
<text x="-1.524" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<pin name="C-" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
<pin name="A+" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LZ1">
<gates>
<gate name="D$1" symbol="1XDIE" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LZ1">
<connects>
<connect gate="D$1" pin="A+" pad="2 3 5"/>
<connect gate="D$1" pin="C-" pad="1 4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Con-amp-micromatch (2)">
<packages>
<package name="MICROMATCH-4">
<description>&lt;b&gt;MicroMaTch 4 &lt;/b&gt; 7-215464-4 / 0-215464-4&lt;p&gt;
Drawing Number C-215464&lt;br&gt;
DDEController.pdf</description>
<wire x1="-3.56" y1="0.7" x2="-3.96" y2="0.7" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="0.7" x2="-3.96" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="-0.7" x2="-3.56" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="-3.56" y1="-1.2" x2="-3.96" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="-1.2" x2="-3.96" y2="-1.6" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="-1.6" x2="-3.56" y2="-1.6" width="0.2032" layer="21"/>
<wire x1="-3.56" y1="1.6" x2="-3.96" y2="1.6" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="1.6" x2="-3.96" y2="1.2" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="1.2" x2="-3.56" y2="1.2" width="0.2032" layer="21"/>
<wire x1="-3.46" y1="2.4" x2="-3.46" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-2.66" y1="2" x2="-2.66" y2="-2" width="0.2032" layer="21"/>
<wire x1="3.36" y1="1.6" x2="3.06" y2="1.6" width="0.1016" layer="21"/>
<wire x1="3.06" y1="1.6" x2="2.76" y2="1.6" width="0.1016" layer="21"/>
<wire x1="3.36" y1="0" x2="3.06" y2="0" width="0.1016" layer="21"/>
<wire x1="3.06" y1="0" x2="2.76" y2="0" width="0.1016" layer="21"/>
<wire x1="3.06" y1="0" x2="2.76" y2="0.3" width="0.1016" layer="21"/>
<wire x1="3.06" y1="1.6" x2="2.76" y2="1.3" width="0.1016" layer="21"/>
<wire x1="2.96" y1="1.4" x2="3.06" y2="1.3" width="0.1016" layer="21"/>
<wire x1="3.36" y1="1.3" x2="3.06" y2="1.3" width="0.1016" layer="21"/>
<wire x1="3.06" y1="1.3" x2="3.06" y2="0.3" width="0.1016" layer="21"/>
<wire x1="3.06" y1="0.3" x2="3.36" y2="0.3" width="0.1016" layer="21"/>
<wire x1="2.96" y1="0.2" x2="3.06" y2="0.3" width="0.1016" layer="21"/>
<wire x1="3.56" y1="-0.7" x2="3.96" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="3.96" y1="-0.7" x2="3.96" y2="0.7" width="0.2032" layer="21"/>
<wire x1="3.96" y1="0.7" x2="3.56" y2="0.7" width="0.2032" layer="21"/>
<wire x1="3.56" y1="1.2" x2="3.96" y2="1.2" width="0.2032" layer="21"/>
<wire x1="3.96" y1="1.2" x2="3.96" y2="1.6" width="0.2032" layer="21"/>
<wire x1="3.96" y1="1.6" x2="3.56" y2="1.6" width="0.2032" layer="21"/>
<wire x1="3.56" y1="-1.6" x2="3.96" y2="-1.6" width="0.2032" layer="21"/>
<wire x1="3.96" y1="-1.6" x2="3.96" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="3.96" y1="-1.2" x2="3.56" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="3.46" y1="-2.4" x2="3.46" y2="2.4" width="0.2032" layer="21"/>
<wire x1="2.66" y1="2" x2="-2.66" y2="2" width="0.2032" layer="21"/>
<wire x1="3.46" y1="2.4" x2="-3.46" y2="2.4" width="0.2032" layer="21"/>
<wire x1="3.46" y1="-2.4" x2="-3.46" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="2.66" y1="-2" x2="2.66" y2="2" width="0.2032" layer="21"/>
<wire x1="2.66" y1="-2" x2="-2.66" y2="-2" width="0.2032" layer="21"/>
<pad name="1" x="1.905" y="1.27" drill="0.8128"/>
<pad name="2" x="0.635" y="-1.27" drill="0.8128"/>
<pad name="3" x="-0.635" y="1.27" drill="0.8128"/>
<pad name="4" x="-1.905" y="-1.27" drill="0.8128"/>
<text x="-2.54" y="2.54" size="1.27" layer="25">&gt;NAME</text>
<text x="-2.54" y="-3.81" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="MICROMATCH-4SMD">
<wire x1="-3.56" y1="0.7" x2="-3.96" y2="0.7" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="0.7" x2="-3.96" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="-0.7" x2="-3.56" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="-3.56" y1="-1.2" x2="-3.96" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="-1.2" x2="-3.96" y2="-1.6" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="-1.6" x2="-3.56" y2="-1.6" width="0.2032" layer="21"/>
<wire x1="-3.56" y1="1.6" x2="-3.96" y2="1.6" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="1.6" x2="-3.96" y2="1.2" width="0.2032" layer="21"/>
<wire x1="-3.96" y1="1.2" x2="-3.56" y2="1.2" width="0.2032" layer="21"/>
<wire x1="-3.46" y1="2.4" x2="-3.46" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="-2.66" y1="2" x2="-2.66" y2="-2" width="0.2032" layer="21"/>
<wire x1="3.36" y1="1.6" x2="3.06" y2="1.6" width="0.1016" layer="21"/>
<wire x1="3.06" y1="1.6" x2="2.76" y2="1.6" width="0.1016" layer="21"/>
<wire x1="3.36" y1="0" x2="3.06" y2="0" width="0.1016" layer="21"/>
<wire x1="3.06" y1="0" x2="2.76" y2="0" width="0.1016" layer="21"/>
<wire x1="3.06" y1="0" x2="2.76" y2="0.3" width="0.1016" layer="21"/>
<wire x1="3.06" y1="1.6" x2="2.76" y2="1.3" width="0.1016" layer="21"/>
<wire x1="2.96" y1="1.4" x2="3.06" y2="1.3" width="0.1016" layer="21"/>
<wire x1="3.36" y1="1.3" x2="3.06" y2="1.3" width="0.1016" layer="21"/>
<wire x1="3.06" y1="1.3" x2="3.06" y2="0.3" width="0.1016" layer="21"/>
<wire x1="3.06" y1="0.3" x2="3.36" y2="0.3" width="0.1016" layer="21"/>
<wire x1="2.96" y1="0.2" x2="3.06" y2="0.3" width="0.1016" layer="21"/>
<wire x1="3.56" y1="-0.7" x2="3.96" y2="-0.7" width="0.2032" layer="21"/>
<wire x1="3.96" y1="-0.7" x2="3.96" y2="0.7" width="0.2032" layer="21"/>
<wire x1="3.96" y1="0.7" x2="3.56" y2="0.7" width="0.2032" layer="21"/>
<wire x1="3.56" y1="1.2" x2="3.96" y2="1.2" width="0.2032" layer="21"/>
<wire x1="3.96" y1="1.2" x2="3.96" y2="1.6" width="0.2032" layer="21"/>
<wire x1="3.96" y1="1.6" x2="3.56" y2="1.6" width="0.2032" layer="21"/>
<wire x1="3.56" y1="-1.6" x2="3.96" y2="-1.6" width="0.2032" layer="21"/>
<wire x1="3.96" y1="-1.6" x2="3.96" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="3.96" y1="-1.2" x2="3.56" y2="-1.2" width="0.2032" layer="21"/>
<wire x1="3.46" y1="-2.4" x2="3.46" y2="2.4" width="0.2032" layer="21"/>
<wire x1="2.66" y1="2" x2="-2.66" y2="2" width="0.2032" layer="21"/>
<wire x1="3.46" y1="2.4" x2="-3.46" y2="2.4" width="0.2032" layer="21"/>
<wire x1="3.46" y1="-2.4" x2="-3.46" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="2.66" y1="-2" x2="2.66" y2="2" width="0.2032" layer="21"/>
<wire x1="2.66" y1="-2" x2="-2.66" y2="-2" width="0.2032" layer="21"/>
<smd name="1" x="1.905" y="-2.54" dx="1.27" dy="3.81" layer="1" rot="R180"/>
<smd name="2" x="0.635" y="2.54" dx="1.27" dy="3.81" layer="1" rot="R180"/>
<smd name="3" x="-0.635" y="-2.54" dx="1.27" dy="3.81" layer="1" rot="R180"/>
<smd name="4" x="-1.905" y="2.54" dx="1.27" dy="3.81" layer="1" rot="R180"/>
<text x="-2.54" y="2.54" size="1.27" layer="25">&gt;NAME</text>
<text x="-2.54" y="-3.81" size="1.27" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="MV">
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="1.27" y2="0" width="0.6096" layer="94"/>
<text x="-0.508" y="0.762" size="1.524" layer="95" rot="R180">&gt;NAME</text>
<text x="0" y="0.889" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="M">
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="1.27" y2="0" width="0.6096" layer="94"/>
<text x="-0.508" y="0.762" size="1.524" layer="95" rot="R180">&gt;NAME</text>
<pin name="S" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MICROMATCH-4" prefix="X">
<description>&lt;b&gt;MicroMaTch 4 &lt;/b&gt; 7-215464-4 / 0-215464-4&lt;p&gt;
Drawing Number C-215464&lt;br&gt;
DDEController.pdf</description>
<gates>
<gate name="-1" symbol="MV" x="-2.54" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="-2.54" y="0" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="-2.54" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="-2.54" y="-5.08" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="MICROMATCH-4">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SMD" package="MICROMATCH-4SMD">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="X1" library="Con-amp-micromatch (2)" deviceset="MICROMATCH-4" device="SMD"/>
<part name="U$2" library="Power_Led" deviceset="LZ1" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="X1" gate="-1" x="-96.52" y="2.54"/>
<instance part="X1" gate="-2" x="-96.52" y="0"/>
<instance part="X1" gate="-3" x="-96.52" y="-2.54"/>
<instance part="X1" gate="-4" x="-96.52" y="-5.08"/>
<instance part="U$2" gate="D$1" x="-68.58" y="2.54" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="X1" gate="-2" pin="S"/>
<label x="-83.82" y="0" size="1.778" layer="95"/>
<pinref part="X1" gate="-1" pin="S"/>
<label x="-83.82" y="2.54" size="1.778" layer="95"/>
<wire x1="-91.44" y1="2.54" x2="-76.2" y2="2.54" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="2.54" x2="-71.12" y2="2.54" width="0.1524" layer="91"/>
<pinref part="U$2" gate="D$1" pin="A+"/>
<wire x1="-91.44" y1="0" x2="-76.2" y2="0" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="0" x2="-76.2" y2="2.54" width="0.1524" layer="91"/>
<junction x="-76.2" y="2.54"/>
</segment>
</net>
<net name="S" class="0">
<segment>
<pinref part="X1" gate="-3" pin="S"/>
<label x="-83.82" y="-2.54" size="1.778" layer="95"/>
<pinref part="X1" gate="-4" pin="S"/>
<label x="-83.82" y="-5.08" size="1.778" layer="95"/>
<wire x1="-91.44" y1="-5.08" x2="-76.2" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="-5.08" x2="-63.5" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="-5.08" x2="-63.5" y2="2.54" width="0.1524" layer="91"/>
<pinref part="U$2" gate="D$1" pin="C-"/>
<wire x1="-66.04" y1="2.54" x2="-63.5" y2="2.54" width="0.1524" layer="91"/>
<wire x1="-91.44" y1="-2.54" x2="-76.2" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="-2.54" x2="-76.2" y2="-5.08" width="0.1524" layer="91"/>
<junction x="-76.2" y="-5.08"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
