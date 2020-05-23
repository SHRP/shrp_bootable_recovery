#!/sbin/sh
cat > /twres/bg_res.xml <<EOF
<?xml version="1.0"?>
<recovery>
	<details>
		<resolution width="1080" height="1920"/>
		<author>Teamwin | epicX</author>
		<title>SKY HAWK RECOVERY PROJECT</title>
		<description>Sky_hawK_bg_color_handler</description>
		<preview>preview.png</preview>
		<themeversion>3</themeversion>
	</details>
	<variables>
		<variable name="c_white" value="$x"/>
		<variable name="c_scolor" value="$y"/>
		<variable name="nav_bg" value="$z"/>
	</variables>
</recovery>
EOF
