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
<package name="LZ4">
<wire x1="3.5" y1="3.3" x2="3.3" y2="3.5" width="0.127" layer="21" curve="-90"/>
<wire x1="3.5" y1="-3.3" x2="3.3" y2="-3.5" width="0.127" layer="21" curve="90"/>
<wire x1="-3.5" y1="-3.3" x2="-3.3" y2="-3.5" width="0.127" layer="21" curve="-90"/>
<wire x1="-3.3" y1="3.5" x2="-3.5" y2="3.3" width="0.127" layer="21" curve="-90"/>
<wire x1="-1.4" y1="3.5" x2="-1.8" y2="3.5" width="0.127" layer="21" curve="-180"/>
<wire x1="-1.4" y1="-3.5" x2="-1.8" y2="-3.5" width="0.127" layer="21" curve="180"/>
<wire x1="-3.5" y1="-1.4" x2="-3.5" y2="-1.8" width="0.127" layer="21" curve="-180"/>
<wire x1="3.5" y1="-1.4" x2="3.5" y2="-1.8" width="0.127" layer="21" curve="180"/>
<circle x="0" y="0" radius="3.1" width="0.127" layer="21"/>
<wire x1="-3.3" y1="3.5" x2="-1.8" y2="3.5" width="0.127" layer="21"/>
<wire x1="-1.4" y1="3.5" x2="3.3" y2="3.5" width="0.127" layer="21"/>
<wire x1="-1.4" y1="-3.5" x2="3.3" y2="-3.5" width="0.127" layer="21"/>
<wire x1="-3.3" y1="-3.5" x2="-1.8" y2="-3.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-3.3" x2="-3.5" y2="-1.8" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.4" x2="-3.5" y2="3.3" width="0.127" layer="21"/>
<wire x1="3.5" y1="-3.3" x2="3.5" y2="-1.8" width="0.127" layer="21"/>
<wire x1="3.5" y1="-1.4" x2="3.5" y2="3.3" width="0.127" layer="21"/>
<polygon width="0" layer="1">
<vertex x="-3.75" y="3.75"/>
<vertex x="-2.25" y="3.75"/>
<vertex x="-2.25" y="2.68"/>
<vertex x="-2.68" y="2.25"/>
<vertex x="-3.75" y="2.25"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="3.75" y="3.75"/>
<vertex x="3.75" y="2.25"/>
<vertex x="2.68" y="2.25"/>
<vertex x="2.25" y="2.68"/>
<vertex x="2.25" y="3.75"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="3.75" y="-3.75"/>
<vertex x="2.25" y="-3.75"/>
<vertex x="2.25" y="-2.68"/>
<vertex x="2.68" y="-2.25"/>
<vertex x="3.75" y="-2.25"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="-3.75" y="-3.75"/>
<vertex x="-3.75" y="-2.25"/>
<vertex x="-2.68" y="-2.25"/>
<vertex x="-2.25" y="-2.68"/>
<vertex x="-2.25" y="-3.75"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="-2.382" y="-0.757"/>
<vertex x="-0.32" y="-0.205"/>
<vertex x="-0.38" y="0.017"/>
<vertex x="-2.442" y="-0.535" curve="-55"/>
<vertex x="-1.847" y="1.685"/>
<vertex x="-0.961" y="0.799"/>
<vertex x="-0.799" y="0.961"/>
<vertex x="-1.685" y="1.847" curve="-55"/>
<vertex x="0.535" y="2.442"/>
<vertex x="-0.017" y="0.38"/>
<vertex x="0.205" y="0.32"/>
<vertex x="0.757" y="2.382" curve="-55"/>
<vertex x="2.382" y="0.757"/>
<vertex x="1.173" y="0.433"/>
<vertex x="1.232" y="0.211"/>
<vertex x="2.442" y="0.535" curve="-55"/>
<vertex x="1.847" y="-1.685"/>
<vertex x="0.337" y="-0.175"/>
<vertex x="0.175" y="-0.337"/>
<vertex x="1.685" y="-1.847" curve="-55"/>
<vertex x="-0.535" y="-2.442"/>
<vertex x="-0.211" y="-1.232"/>
<vertex x="-0.433" y="-1.173"/>
<vertex x="-0.757" y="-2.382" curve="-55"/>
</polygon>
<smd name="5" x="-3.175" y="-3.175" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<smd name="6" x="-1.495" y="-3.195" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<smd name="1" x="3.175" y="3.175" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<smd name="7" x="3.175" y="-3.175" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<smd name="9" x="0" y="0" dx="0.3" dy="0.3" layer="1" roundness="100"/>
<polygon width="0" layer="1">
<vertex x="-2.05" y="3.75"/>
<vertex x="-0.85" y="3.75"/>
<vertex x="-0.85" y="2.757" curve="-70.268077"/>
<vertex x="-0.983" y="2.568" curve="20.2601"/>
<vertex x="-1.725" y="2.142" curve="-131.264747"/>
<vertex x="-2.05" y="2.298"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="-3.75" y="-2.05"/>
<vertex x="-3.75" y="-0.85"/>
<vertex x="-2.757" y="-0.85" curve="-70.268077"/>
<vertex x="-2.568" y="-0.983" curve="20.2601"/>
<vertex x="-2.142" y="-1.725" curve="-131.264747"/>
<vertex x="-2.298" y="-2.05"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="-2.05" y="-3.75"/>
<vertex x="-0.85" y="-3.75"/>
<vertex x="-0.85" y="-2.757" curve="70.268077"/>
<vertex x="-0.983" y="-2.568" curve="-20.260149"/>
<vertex x="-1.725" y="-2.142" curve="131.264747"/>
<vertex x="-2.05" y="-2.298" curve="-2.546462"/>
</polygon>
<polygon width="0" layer="1">
<vertex x="3.75" y="-2.05"/>
<vertex x="3.75" y="-0.85"/>
<vertex x="2.757" y="-0.85" curve="70.268077"/>
<vertex x="2.568" y="-0.983" curve="-20.260149"/>
<vertex x="2.142" y="-1.725" curve="131.264747"/>
<vertex x="2.298" y="-2.05" curve="-2.546462"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-3.75" y="3.75"/>
<vertex x="-2.25" y="3.75"/>
<vertex x="-2.25" y="2.68"/>
<vertex x="-2.68" y="2.25"/>
<vertex x="-3.75" y="2.25"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="3.75" y="3.75"/>
<vertex x="3.75" y="2.25"/>
<vertex x="2.68" y="2.25"/>
<vertex x="2.25" y="2.68"/>
<vertex x="2.25" y="3.75"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="3.75" y="-3.75"/>
<vertex x="2.25" y="-3.75"/>
<vertex x="2.25" y="-2.68"/>
<vertex x="2.68" y="-2.25"/>
<vertex x="3.75" y="-2.25"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-3.75" y="-3.75"/>
<vertex x="-3.75" y="-2.25"/>
<vertex x="-2.68" y="-2.25"/>
<vertex x="-2.25" y="-2.68"/>
<vertex x="-2.25" y="-3.75"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-2.382" y="-0.757"/>
<vertex x="-0.32" y="-0.205"/>
<vertex x="-0.38" y="0.017"/>
<vertex x="-2.442" y="-0.535" curve="-55"/>
<vertex x="-1.847" y="1.685"/>
<vertex x="-0.961" y="0.799"/>
<vertex x="-0.799" y="0.961"/>
<vertex x="-1.685" y="1.847" curve="-55"/>
<vertex x="0.535" y="2.442"/>
<vertex x="-0.017" y="0.38"/>
<vertex x="0.205" y="0.32"/>
<vertex x="0.757" y="2.382" curve="-55"/>
<vertex x="2.382" y="0.757"/>
<vertex x="1.173" y="0.433"/>
<vertex x="1.232" y="0.211"/>
<vertex x="2.442" y="0.535" curve="-55"/>
<vertex x="1.847" y="-1.685"/>
<vertex x="0.337" y="-0.175"/>
<vertex x="0.175" y="-0.337"/>
<vertex x="1.685" y="-1.847" curve="-55"/>
<vertex x="-0.535" y="-2.442"/>
<vertex x="-0.211" y="-1.232"/>
<vertex x="-0.433" y="-1.173"/>
<vertex x="-0.757" y="-2.382" curve="-55"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-2.05" y="3.75"/>
<vertex x="-0.85" y="3.75"/>
<vertex x="-0.85" y="2.757" curve="-70.268077"/>
<vertex x="-0.983" y="2.568" curve="20.2601"/>
<vertex x="-1.725" y="2.142" curve="-131.264747"/>
<vertex x="-2.05" y="2.298"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-3.75" y="-2.05"/>
<vertex x="-3.75" y="-0.85"/>
<vertex x="-2.757" y="-0.85" curve="-70.268077"/>
<vertex x="-2.568" y="-0.983" curve="20.2601"/>
<vertex x="-2.142" y="-1.725" curve="-131.264747"/>
<vertex x="-2.298" y="-2.05"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="-2.05" y="-3.75"/>
<vertex x="-0.85" y="-3.75"/>
<vertex x="-0.85" y="-2.757" curve="70.268077"/>
<vertex x="-0.983" y="-2.568" curve="-20.260149"/>
<vertex x="-1.725" y="-2.142" curve="131.264747"/>
<vertex x="-2.05" y="-2.298" curve="-2.546462"/>
</polygon>
<polygon width="0.127" layer="29">
<vertex x="3.75" y="-2.05"/>
<vertex x="3.75" y="-0.85"/>
<vertex x="2.757" y="-0.85" curve="70.268077"/>
<vertex x="2.568" y="-0.983" curve="-20.260149"/>
<vertex x="2.142" y="-1.725" curve="131.264747"/>
<vertex x="2.298" y="-2.05" curve="-2.546462"/>
</polygon>
<smd name="4" x="-3.195" y="-1.495" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<smd name="8" x="3.155" y="-1.475" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<smd name="2" x="-1.465" y="3.195" dx="1.07" dy="1.07" layer="1" rot="R90"/>
<circle x="0" y="0" radius="3.1" width="0.127" layer="21"/>
<smd name="3" x="-3.085" y="3.105" dx="1.07" dy="1.07" layer="1" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="LZ4-00U610">
<wire x1="0.127" y1="8.89" x2="2.413" y2="7.62" width="0.254" layer="94"/>
<wire x1="2.413" y1="7.62" x2="0.127" y2="6.35" width="0.254" layer="94"/>
<wire x1="2.413" y1="8.89" x2="2.413" y2="7.62" width="0.254" layer="94"/>
<wire x1="2.413" y1="7.62" x2="2.413" y2="6.35" width="0.254" layer="94"/>
<wire x1="0.127" y1="8.89" x2="0.127" y2="6.35" width="0.254" layer="94"/>
<wire x1="0.127" y1="5.969" x2="1.524" y2="4.572" width="0.1524" layer="94"/>
<wire x1="1.27" y1="6.096" x2="2.667" y2="4.699" width="0.1524" layer="94"/>
<polygon width="0.1524" layer="94">
<vertex x="1.524" y="4.572"/>
<vertex x="0.635" y="4.953"/>
<vertex x="1.143" y="5.461"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="2.667" y="4.699"/>
<vertex x="1.778" y="5.08"/>
<vertex x="2.286" y="5.588"/>
</polygon>
<wire x1="2.286" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="0" y1="7.62" x2="-2.54" y2="7.62" width="0.254" layer="94"/>
<wire x1="13.97" y1="-0.127" x2="12.7" y2="-2.413" width="0.254" layer="94"/>
<wire x1="12.7" y1="-2.413" x2="11.43" y2="-0.127" width="0.254" layer="94"/>
<wire x1="13.97" y1="-2.413" x2="12.7" y2="-2.413" width="0.254" layer="94"/>
<wire x1="12.7" y1="-2.413" x2="11.43" y2="-2.413" width="0.254" layer="94"/>
<wire x1="13.97" y1="-0.127" x2="11.43" y2="-0.127" width="0.254" layer="94"/>
<wire x1="11.049" y1="-0.127" x2="9.652" y2="-1.524" width="0.1524" layer="94"/>
<wire x1="11.176" y1="-1.27" x2="9.779" y2="-2.667" width="0.1524" layer="94"/>
<polygon width="0.1524" layer="94">
<vertex x="9.652" y="-1.524"/>
<vertex x="10.033" y="-0.635"/>
<vertex x="10.541" y="-1.143"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="9.779" y="-2.667"/>
<vertex x="10.16" y="-1.778"/>
<vertex x="10.668" y="-2.286"/>
</polygon>
<wire x1="12.7" y1="-2.286" x2="12.7" y2="-5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="12.7" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.413" y1="-11.43" x2="0.127" y2="-10.16" width="0.254" layer="94"/>
<wire x1="0.127" y1="-10.16" x2="2.413" y2="-8.89" width="0.254" layer="94"/>
<wire x1="0.127" y1="-11.43" x2="0.127" y2="-10.16" width="0.254" layer="94"/>
<wire x1="0.127" y1="-10.16" x2="0.127" y2="-8.89" width="0.254" layer="94"/>
<wire x1="2.413" y1="-11.43" x2="2.413" y2="-8.89" width="0.254" layer="94"/>
<wire x1="2.413" y1="-8.509" x2="1.016" y2="-7.112" width="0.1524" layer="94"/>
<wire x1="1.27" y1="-8.636" x2="-0.127" y2="-7.239" width="0.1524" layer="94"/>
<polygon width="0.1524" layer="94">
<vertex x="1.016" y="-7.112"/>
<vertex x="1.905" y="-7.493"/>
<vertex x="1.397" y="-8.001"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-0.127" y="-7.239"/>
<vertex x="0.762" y="-7.62"/>
<vertex x="0.254" y="-8.128"/>
</polygon>
<wire x1="0.254" y1="-10.16" x2="-2.54" y2="-10.16" width="0.254" layer="94"/>
<wire x1="2.54" y1="-10.16" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-11.43" y1="-2.413" x2="-10.16" y2="-0.127" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-0.127" x2="-8.89" y2="-2.413" width="0.254" layer="94"/>
<wire x1="-11.43" y1="-0.127" x2="-10.16" y2="-0.127" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-0.127" x2="-8.89" y2="-0.127" width="0.254" layer="94"/>
<wire x1="-11.43" y1="-2.413" x2="-8.89" y2="-2.413" width="0.254" layer="94"/>
<wire x1="-8.509" y1="-2.413" x2="-7.112" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="-8.636" y1="-1.27" x2="-7.239" y2="0.127" width="0.1524" layer="94"/>
<polygon width="0.1524" layer="94">
<vertex x="-7.112" y="-1.016"/>
<vertex x="-7.493" y="-1.905"/>
<vertex x="-8.001" y="-1.397"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-7.239" y="0.127"/>
<vertex x="-7.62" y="-0.762"/>
<vertex x="-8.128" y="-0.254"/>
</polygon>
<wire x1="-10.16" y1="-0.254" x2="-10.16" y2="2.54" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-2.54" x2="-10.16" y2="-5.08" width="0.254" layer="94"/>
<pin name="1" x="-5.08" y="7.62" visible="pad" length="short" direction="pas"/>
<pin name="3" x="12.7" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
<pin name="5" x="7.62" y="-10.16" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="7" x="-10.16" y="-7.62" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="2" x="7.62" y="7.62" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="4" x="12.7" y="-7.62" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="6" x="-5.08" y="-10.16" visible="pad" length="short" direction="pas"/>
<pin name="8" x="-10.16" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
<circle x="-17.78" y="-5.08" radius="2.54" width="0.254" layer="94"/>
<pin name="9" x="-17.78" y="0" visible="pad" length="short" direction="pas" rot="R270"/>
<text x="2.54" y="12.7" size="1.27" layer="95" rot="R180">&gt;NAME</text>
<text x="2.54" y="-15.24" size="1.27" layer="96" rot="R180">&gt;VALUE</text>
<text x="-18.796" y="-5.334" size="1.27" layer="94">TH</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="LZ4">
<gates>
<gate name="G$1" symbol="LZ4-00U610" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LZ4">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
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
<part name="U$1" library="Power_Led" deviceset="LZ4" device=""/>
<part name="X1" library="Con-amp-micromatch (2)" deviceset="MICROMATCH-4" device="SMD"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-45.72" y="0"/>
<instance part="X1" gate="-1" x="-96.52" y="2.54"/>
<instance part="X1" gate="-2" x="-96.52" y="0"/>
<instance part="X1" gate="-3" x="-96.52" y="-2.54"/>
<instance part="X1" gate="-4" x="-96.52" y="-5.08"/>
</instances>
<busses>
</busses>
<nets>
<net name="2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="2"/>
<wire x1="-38.1" y1="7.62" x2="-35.56" y2="7.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="3"/>
<wire x1="-33.02" y1="5.08" x2="-33.02" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="4"/>
<wire x1="-33.02" y1="-7.62" x2="-33.02" y2="-10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="5"/>
<wire x1="-38.1" y1="-10.16" x2="-35.56" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="6"/>
<wire x1="-50.8" y1="-10.16" x2="-53.34" y2="-10.16" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="7"/>
<wire x1="-55.88" y1="-7.62" x2="-55.88" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="X1" gate="-1" pin="S"/>
<wire x1="-91.44" y1="2.54" x2="-86.36" y2="2.54" width="0.1524" layer="91"/>
<label x="-83.82" y="2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X1" gate="-2" pin="S"/>
<wire x1="-91.44" y1="0" x2="-86.36" y2="0" width="0.1524" layer="91"/>
<label x="-83.82" y="0" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="1"/>
<wire x1="-53.34" y1="7.62" x2="-50.8" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="S" class="0">
<segment>
<pinref part="X1" gate="-3" pin="S"/>
<wire x1="-91.44" y1="-2.54" x2="-86.36" y2="-2.54" width="0.1524" layer="91"/>
<label x="-83.82" y="-2.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="X1" gate="-4" pin="S"/>
<wire x1="-91.44" y1="-5.08" x2="-86.36" y2="-5.08" width="0.1524" layer="91"/>
<label x="-83.82" y="-5.08" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="8"/>
<wire x1="-55.88" y1="5.08" x2="-55.88" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
