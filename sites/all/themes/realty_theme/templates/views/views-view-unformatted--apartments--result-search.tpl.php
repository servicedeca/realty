<div class="container fin">
  <div class="col-xs-12 table-block text-center zero-padding">

    <table class="table issue-table display" id="example">

      <thead>
        <tr>
          <th id="bn"><?php print t('Apartment') ?></th>
          <th><?php print t('Area') ?></th>
          <th><?php print t('Developer') ?></th>
          <th><?php print t('RC') ?></th>
          <th><?php print t('Address') ?></th>
          <th><?php print t('Deadline') ?></th>
          <th><?php print t('Rooms') ?>.&nbsp&nbsp</th>
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
        <?php if (!empty($view->result)):?>
          <?php foreach($apartments as $key=>$apartment) :?>
            <?php if ($apartment['status'] == 0):?>
              <tr title="Квартира забронирована" class="booking">
            <?php else: ?>
              <tr>
            <?php endif?>
            <td  scope="row" class="no-hover anchor">
              <?php print $apartment['number']?>
              <?php print $apartment['apartment_comparison']?>
              <?php if ($apartment['status'] == 0):?>
              <span id="signal">
                <?php print $apartment['apartment_signal']?>
              </span>
              <?php endif?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['area']?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['developer_path']?>"' >
              <?php print $apartment['developer']?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['complex_path']?>"' >
              <?php print $apartment['complex']?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['address']?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['quarter'] . 'кв.' . $apartment['year'] ?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['rooms']?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['floor'] . '/' . $apartment['home_floor'] ?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['sq'] . 'м'?><sup>2</sup>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['price']?>
            </td>
            <td class="anchor" onClick='location.href="<?php print $apartment['apartment_path']?>"' >
              <?php print $apartment['coast']?>
            </td>
          </tr>
        <?php endforeach;?>
        <?php endif; ?>
      </tbody>
    </table>
  </div>
</div>