<table class="table issue-table display col-xs-12 zero-padding" id="complex">
  <thead>
  <tr>
    <th id="bn">
      <?php print t('Apartment')?>
    </th>
    <th>
      <?php print t('Address');?>
    </th>
    <th>
      <?php print t('Section');?>
    </th>
    <th>
      <?php print t('Rooms') . '&nbsp&nbsp'?>
    </th>
    <th data-sort="field_apartment_floor_value"  data-order="ASC" class="sort sorting">
      <?php print t('floor') . '&nbsp&nbsp';?>
    </th>
    <th data-sort="field_gross_area_value" data-order="ASC" class="sort sorting">
      <?php print t('SQ');?>
    </th>
    <th data-sort="field_price_value" data-order="ASC" class="sort sorting">
      <?php print t('Price')?><br>м<sup>2</sup>&nbsp&nbsp
    </th>
    <th data-sort="field_full_cost_value" data-order="ASC" class="sort sorting">
      <?php print t('Coast');?>
    </th>
  </tr>
  </thead>
  <tbody>
  <?php if($apartments):?>
    <?php foreach($apartments as $apartment):?>
      <?php if ($apartment['status'] == 0):?>
        <tr title="Квартира забронирована" class="booking">
      <?php else: ?>
        <tr>
      <?php endif?>
      <td scope="row" class="no-hover anchor">
        <?php print $apartment['number']?>
        <?php print $apartment['comparison'];?>
        <?php if(isset($apartment['dindong'])):?>
          <?php print $apartment['dindong'];?>
        <?php endif?>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['address']?>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['section']?>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['room']?>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['floor']?>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['sq'] . 'м'?><sup>2</sup>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['price']?>
      </td>
      <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"'>
        <?php print $apartment['coast']?>
      </td>
      </tr>
    <?php endforeach;?>
  <?php endif;?>
  </tbody>
</table>