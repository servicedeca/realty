<?php print render($form['name'])?>
<?php print render($form['description'])?>
<?php print render($form['field_address_house'])?>
<?php print render($form['field_number_home']);?>
<?php print render($form['field_home_complex'])?>
<?php print render($form['field_masonry'])?>
<?php print render($form['field_number_floor'])?>
<?php print render($form['field_map'])?>
<?php print render($form['field_category'])?>
<h1>
<?php print t('Расположение на плане жк')?>
</h1>
<div id="add-home-plan">
  <?php print t('Oтметить дом на плане ЖК')?>
</div>
<div id="mark-tools">
  <?php print $tool_add_complex?>
</div>
<div class="div-plan-complex">

</div>

<h1>
  <?php print t('Расположение Секций')?>
</h1>
<?php print render($form['field_home_plan']) ?>
<div id="add-section-plan">
  <?php print t('Oтметить секцию на плане дома')?>
</div>
<div id="mark-tools">
  <?php print $tool_add_section?>
</div>
<div class="div-plan-home">
    <?php if(!empty($form['field_home_plan']['und'][0]['#entity']->field_home_plan)):?>
      <?php print render($image_home_plan)?>
        <?php if(isset($sections)):?>
          <?php foreach($sections as $val):?>
            <?php print $val ?>
          <?php endforeach;?>
        <?php endif;?>
    <?php endif;?>
</div>

<?php print render($form['field_plan_floor'])?>
<?php //print render($form['field_home_section'][LANGUAGE_NONE][0]['field_lage_plan_home'])?>
<?php //print render($form['field_home_section']['und']['add_more']) ?>
<?php //print render($form['field_home_section'])?>

<h1>
  <?php print t('Расположение квартир')?>
</h1>
<div id="add-apartments-plan">
  <?php print t('Oтметить квартиры')?>
</div>

<div id="add-apartments-plan-form">
</div>


<?php print render($form['actions'])?>

<div class="element-hidden">
  <?php print drupal_render_children($form)?>
</div>